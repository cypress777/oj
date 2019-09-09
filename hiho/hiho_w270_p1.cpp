#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Area {
    int left, right;
    double water;

    explicit Area() {}
    Area(int l, int r, double w) : left(l), right(r), water(w) {}
};

vector<Area> change(const vector<Area> &areas, vector<int> &height) {
    vector<Area> new_area;

    for (auto area : areas) {
        if ((area.left >= 0 || height[area.left] > height[area.left - 1]) &&
            (area.right == height.size() - 1 || height[area.right] > height[area.right + 1]) {

            int new_left = area.left - 1;
            int new_right = area.left - 1;
            while (new_left == 0 || (new_left > 0 && height[new_left] >= height[new_left - 1])) {
                new_left--;
                if (height[new_left] < height[new_left + 1]) new_right = new_left;
            }

            new_area.push_back(Area(new_left, area.left - 1, area.water / 2))
        }
    }
}

int main() {
    int N, S, M, T;
    cin >> N >> S >> M >> T;
    S--, T--;

    vector<int> ori_h(N);
    for (int i = 0; i < N; i++) {
        cin >> ori_h[i];
    }

    vector<int> cur_h = ori_h;

    vector<Area> areas(1);
    areas[0] = Area(S, S, double(M));

    while (areas.empty()) {
        auto areas = change(areas, cur_h);
    }

    return 0;
}

