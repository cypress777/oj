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
            if (i > 0 && base_height[i] == base_height[i - 1]) {
                root[i] = root[i - 1];
                continue;
            }

            root[i] = i;
            areas[i].left = i;
            areas[i].right = i;
            areas[i].height = base_height[i];
        }
    }

    void get_root(int i) {

    }

    void get_area(int i) {

    }

    void quick_union(int i, int j, double h) {

    }

    void reset(int i, double h) {

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

vector<Area> change(const vector<Area> &areas, vector<double> &height) {
    vector<Area> new_areas;

//    cout << "-----" << endl;

    for (auto area : areas) {
//        cout << area.left << " " << area.right << " " << area.height << endl;

        if (area.left < 0 || area.right >= height.size()) continue;

        if ((area.left > 0 && height[area.left] == height[area.left - 1]) ||
            (area.right < height.size() - 1 && height[area.right] == height[area.right + 1])) {
//            cout << "expand" << endl;
            expand(area, new_areas, height);
        } else if ((area.left == 0 || height[area.left] > height[area.left - 1]) &&
                   (area.right == height.size() - 1 || height[area.right] > height[area.right + 1])) {
//            cout << "split" << endl;
            split(area, new_areas, height);
        } else if ((area.left == 0 || height[area.left] > height[area.left - 1]) ||
                   (area.right == height.size() - 1 || height[area.right] > height[area.right + 1])) {
//            cout << "transfer" << endl;
            transfer(area, new_areas, height);
        } else {
//            cout << "fill" << endl;
            fill(area, new_areas, height);
        }
    }

    return new_areas;
}

int main() {
    int N, S, M, T;
    cin >> N >> S >> M >> T;
    S--, T--;

    vector<double> ori_h(N);
    for (int i = 0; i < N; i++) {
        cin >> ori_h[i];
    }

    QuickUnion realtime_h(ori_h);

    pair<int, double> injections;

    int cnt = 0;
    while (!injections.empty()) {
        injections = change(injections, realtime_h);

        cnt++;
        if (cnt > 100) break;
    }

//    cout << "==== res: " << endl;
//    for (auto h : cur_h) cout << h << " ";
//    cout << endl;

    cout << floor(realtime_h.get_area(T).height - ori_h[T]) << endl;

    return 0;
}

