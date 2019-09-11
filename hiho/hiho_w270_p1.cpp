#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double eps = 1e-6;

struct Area {
    int left, right;
    double height;

    explicit Area() {}
    Area(int l, int r, double w) : left(l), right(r), height(w) {}
};

struct QuickUnion {
    vector<int> root, size;
    vector<Area> areas;

    QuickUnion(const vector<int> &base_height) {
        int len = base_height.size();

        root = vector<int>(len);
        size = vector<int>(len, 1);
        areas = vector<Area>(len);

        for (int i = 0; i < len; i++) {
            root[i] = i;
            areas[i].left = i;
            areas[i].right = i;
            areas[i].height = base_height[i];
        }

        for (int i = 1; i < len; i++) {
            quick_union(i - 1, i);
        }
    }

    int get_root(int i) {
        if (i < 0 || i >= areas.size()) return i;

        int r = root[i];
        if (r == i) return i;
        root[i] = get_root(r);
        return root[i];
    }

    Area get_area(int i) {
        int r = get_root(i);
        return areas[r];
    }

    void quick_union(int i, int j) {
        int ri = get_root(i), rj = get_root(j);
        if (ri == rj || fabs(areas[ri].height - areas[rj].height) > eps) return;
        if (areas[ri].left - areas[rj].right > 1 || areas[rj].left - areas[ri].right > 1) return;

        int maxr = size[ri] > size[rj] ? ri : rj;
        int minr = size[ri] > size[rj] ? rj : ri;

        size[maxr] += size[minr];
        areas[maxr].left = min(areas[ri].left, areas[rj].left);
        areas[maxr].right = max(areas[ri].right, areas[rj].right);
        root[minr] = maxr;
    }

    void reset(int i, double h) {
        int root_i = get_root(i);
        areas[root_i].height = h;

        int left_i = areas[root_i].left - 1;
        if (left_i >= 0) quick_union(left_i, i);

        int right_i = areas[root_i].right + 1;
        if (right_i < areas.size()) quick_union(right_i, i);
    }
};

void push_injection(vector<pair<int, double>> &injections, pair<int, double> new_injection, QuickUnion &rt_h) {
    bool existed = false;
    for (int i = 0; i < injections.size(); i++) {
        if (rt_h.get_root(injections[i].first) == rt_h.get_root(new_injection.first)) {
            injections[i].second += new_injection.second;
            existed = true;
            break;
        }
    }
    if (!existed) injections.push_back(new_injection);
}

vector<pair<int, double>> change(const vector<pair<int, double>> &injections, QuickUnion &rt_h) {
    vector<pair<int, double>> new_injections;

//    cout << "----- " << injections.size() << endl;

    for (auto injection : injections) {
        int N = rt_h.areas.size();

        if (injection.first < 0 || injection.first >= N || injection.second < eps) continue;
        //        cout << injection.first << " " << area.left << " " << area.right << " " << injection.second << endl;

        Area area = rt_h.get_area(injection.first);
        Area left_area = (area.left > 0 ? rt_h.get_area(area.left - 1) : Area(-1, -1, -1000));
        Area right_area = (area.right < N - 1 ?
                           rt_h.get_area(area.right + 1) : Area(N, N, -1000));

        if (area.height > left_area.height && area.height > right_area.height) {
//            cout << "split" << endl;
            push_injection(new_injections, pair<int, double>(area.left - 1, injection.second / 2.0), rt_h);
            push_injection(new_injections, pair<int, double>(area.right + 1, injection.second / 2.0), rt_h);
        } else if (area.height > left_area.height + eps || area.height > right_area.height + eps) {
//            cout << "transfer" << endl;
            if (area.height > left_area.height + eps) {
                push_injection(new_injections, pair<int, double>(area.left - 1, injection.second), rt_h);
            } else {
                push_injection(new_injections, pair<int, double>(area.right + 1, injection.second), rt_h);
            }
        } else {
//            cout << "fill" << endl;
            double bottom = area.right - area.left + 1;
            double max_water_height = injection.second / bottom;
            double max_volume_height = min(left_area.height - area.height,
                                           right_area.height - area.height);
            double increase_height = min(max_water_height, max_volume_height);

            rt_h.reset(area.left, area.height + increase_height);

            if (max_water_height > max_volume_height + eps) {
                double remain_volume = (max_water_height - max_volume_height) * bottom;
                push_injection(new_injections, pair<int, double>(area.left, remain_volume), rt_h);
            }
        }
    }

    return new_injections;
}

int main() {
    int N, S, M, T;
    cin >> N >> S >> M >> T;
    S--, T--;

    vector<int> ori_h(N);
    for (int i = 0; i < N; i++) {
        cin >> ori_h[i];
    }

    QuickUnion rt_h(ori_h);

    vector<pair<int, double>> injections;
    injections.push_back(pair<int, double>(S, M));

    while (!injections.empty()) {
        injections = change(injections, rt_h);
    }

//    for (int i = 0; i < ori_h.size(); i++) {
//        cout << rt_h.get_area(i).height << " ";
//    }
//    cout << endl;

    cout << int(floor(rt_h.get_area(T).height + eps)) - ori_h[T] << endl;

    return 0;
}

