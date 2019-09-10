#include <iostream>
#include <vector>
#include <cmath>
#include <pair>

using namespace std;

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

    void get_root(int i) {
        int r = root[i];
        if (r == i) return i;
        root[i] = get_root(r);
        return root[i];
    }

    void get_area(int i) {
        int r = get_root(i);
        return areas[r];
    }

    void quick_union(int i, int j) {
        int ri = get_root(i), rj = get_root(j);
        if (ri == rj || areas[ri].height != areas[rj].height) return;
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

        int root_ight_i = areas[ri].right + 1;
        if (right_i < areas.size()) quick_union(right_i, i);
    }
};

void fill(const pair<int, double> &injection, vector<pair<int, double>> &new_injections, vector<double> &rt_h) {
    double bottom = area.right - area.left + 1;
    double max_water_height = area.height / bottom;
    double max_volume_height = min(height[area.left - 1] - height[area.left],
                                   height[area.right + 1] - height[area.right]);
    double increase_height = min(max_water_height, max_volume_height);

    for (int i = area.left; i <= area.right; i++) {
        height[i] += increase_height;
    }

    if (max_water_height > max_volume_height) {
        double remain_height = (max_water_height - max_volume_height) * bottom;
        new_areas.push_back(Area(area.left, area.right, remain_height));
    }
}

pair<int, double> change(const vector<pair<int, double>> &injections, QuickUnion &rt_h) {
    vector<Area> new_injections;

//    cout << "-----" << endl;

    for (auto injection : injections) {
        Area area = rt_h.get_area(injection.first);
        Area left_area = (area.left > 0 ? rt_h.get_area(area.left - 1) : Area(-1, -1, -1000));
        Area right_area = (area.right < rt_h.size() - 1 ?
                           rt_h.get_area(area.right + 1) : Area(rt_h.size(), rt_h.size(), -1000));
//        cout << injection.first << " " << area.left << " " << area.right << " " << injection.second << endl;

        if (area.left < 0 || area.right >= height.size()) continue;

        if (area.height > left_area.height && area.height > right_area.height) {
//            cout << "split" << endl;
            new_injections.push_back(pair<int, double>(area.left - 1, injection.second / 2.0));
            new_injections.push_back(pair<int, double>(area.right + 1, injection.second / 2.0));
        } else if (area.height > left_area.height || area.height > right_area.height) {
//            cout << "transfer" << endl;
            if (area.height > left_area.height) {
                new_injections.push_back(pair<int, double>(area.left - 1, injection.second));
            } else {
                new_injections.push_back(pair<int, double>(area.right + 1, injection.second));
            }
        } else {
//            cout << "fill" << endl;
            double bottom = area.right - area.left + 1;
            double max_water_height = injection.second / bottom;
            double max_volume_height = min(left_area.height - area.height,
                                           right_area.height - area.height);
            double increase_height = min(max_water_height, max_volume_height);

            rt_h.reset(area.left, area.height + increase_height);

            if (max_water_height > max_volume_height) {
                double remain_volume = (max_water_height - max_volume_height) * bottom;
                new_injections.push_back(pair<int, double>(area.left, remain_volume));
            }
        }
    }

    return new_injections;
}

int main() {
    int N, S, M, T;
    cin >> N >> S >> M >> T;
    S--, T--;

    vector<double> ori_h(N);
    for (int i = 0; i < N; i++) {
        cin >> ori_h[i];
    }

    QuickUnion rt_h(ori_h);

    vector<pair<int, double>> injections;
    injections.push_back(pair<int, double>(S, M));

    int cnt = 0;
    while (!injections.empty()) {
        injections = change(injections, rt_h);

        cnt++;
        if (cnt > 100) break;
    }

//    cout << "==== res: " << endl;
//    for (auto h : cur_h) cout << h << " ";
//    cout << endl;

    cout << floor(rt_h.get_area(T).height - ori_h[T]) << endl;

    return 0;
}

