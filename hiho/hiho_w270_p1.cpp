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
        int ri = get_root(i);
        areas[ri].height = h;

        int left_area = areas[ri].left - 1;
        if (left_area >= 0) quick_union(left_area, i);

        int right_area = areas[ri].right + 1;
        if (right_area < areas.size()) quick_union(right_area, i);
    }
};

void expand(const Area &area, vector<Area> &new_areas, vector<double> &height) {
    auto new_area = area;

    while (new_area.left == 0 ||
          (new_area.left > 0 && height[new_area.left] == height[new_area.left - 1])) {
        new_area.left--;
    }

    while (new_area.right == height.size() - 1 ||
           (new_area.right < height.size() - 1 && height[new_area.right] == height[new_area.right + 1])) {
        new_area.right++;
    }

    new_areas.push_back(new_area);
}

void transfer(const Area &area, vector<Area> &new_areas, vector<double> &height) {
    if (area.left == 0 || height[area.left] > height[area.left - 1]) {
        new_areas.push_back(Area(area.left - 1, area.left - 1, area.height));
    } else {
        new_areas.push_back(Area(area.right + 1, area.right + 1, area.height));
    }
}

void split(const Area &area, vector<Area> &new_areas, vector<double> &height) {
    new_areas.push_back(Area(area.left - 1, area.left - 1, area.height / 2.0));
    new_areas.push_back(Area(area.right + 1, area.right + 1, area.height / 2.0));
}

void fill(const Area &area, vector<Area> &new_areas, vector<double> &height) {
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

pair<int, double> change(const pair<int, double> &injections, QuickUnion &rt_h) {
    vector<Area> new_injections;

//    cout << "-----" << endl;

    for (auto injection : injections) {
        Area area = rt_h.get_area(injection.first);
        Area left_area = area.left > 0 ? rt_h.get_area(area.left - 1) : Area(-1, -1, -1);
        Area right_area = area.right < rt_h.size() - 1 ? rt_h.get_area(area.right + 1) : Area(-1, -1, -1);
//        cout << area.left << " " << area.right << endl;

        if (area.left < 0 || area.right >= height.size()) continue;

        if ((area.left == 0 || area.height > left_area.height) &&
            (area.right == height.size() - 1 || area.height > right_area.height)) {
//            cout << "split" << endl;
            split(injection, new_injections, rt_h);
        } else if ((injection.left == 0 || height[injection.left] > height[injection.left - 1]) ||
                   (injection.right == height.size() - 1 || height[injection.right] > height[injection.right + 1])) {
//            cout << "transfer" << endl;
            transfer(injection, new_injections, rt_h);
        } else {
//            cout << "fill" << endl;
            fill(injection, new_injections, rt_h);
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

    pair<int, double> injections;

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

