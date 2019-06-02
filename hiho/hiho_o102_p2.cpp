#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Area {
    int start_, end_;

    Area() {}

    Area(int s, int e) : start_(s), end_(e) {}
};

bool comp(Area a, Area b) {
    if (a.start_ == b.start_) return a.end_ < b.end_;
    return a.start_ < b.start_;
}

vector<Area> merge_zone(vector<Area> &zones) {
    sort(zones.begin(), zones.end(), comp);

    vector<Area> merged;
    int start = zones[0].start_, end = zones[0].end_;
    for (int j = 0; j < zones.size(); j++) {
        if (zones[j].start_ <= zones[j - 1].end_) {
            end = max(end, zones[j].end_);
            if (j == zones.size() - 1) merged.push_back(Area(start, end));
        } else {
            merged.push_back(Area(start, end));
            start = zones[j].start_;
            end = zones[j].end_;
        }
    }

    return merged;
}

bool is_safe(int pos, const vector<Area> &areas) {
    if (areas.empty()) return true;
    int f = 0, r = areas.size(), m;
    while (f < r - 1) {
        m = (r + f) / 2;
        if (areas[m].start_ <= pos) {
            f = m;
        } else if (areas[m].start_ > pos) {
            r = m;
        }
    }
    return areas[f].end_ < pos;
}

int main() {
    int N, M;
    cin >> N >> M;

    unordered_map<int, vector<Area>> x_zones;
    unordered_map<int, vector<Area>> y_zones;

    vector<int> tx(N);
    vector<int> ty(N);
    for (int i = 0; i < N; i++) {
        cin >> tx[i] >> ty[i];
    }

    vector<int> bx(M);
    vector<int> by(M);
    vector<int> bd(M);
    for (int i = 0; i < M; i++) {
        cin >> bx[i] >> by[i] >> bd[i];
        y_zones[bx[i]].push_back(Area(by[i] - bd[i], by[i] + bd[i]));
        x_zones[by[i]].push_back(Area(bx[i] - bd[i], bx[i] + bd[i]));
    }

    for (auto z : x_zones) {
        x_zones[z.first] = merge_zone(z.second);
    }

    for (auto z : y_zones) {
        y_zones[z.first] = merge_zone(z.second);
    }

    int remain = 0;
    for (int i = 0; i < N; i++) {
        bool safe = ((x_zones.find(ty[i]) == x_zones.end() || is_safe(tx[i], x_zones[ty[i]])) &&
                     (y_zones.find(tx[i]) == y_zones.end() || is_safe(ty[i], y_zones[tx[i]])));

        if (safe) remain++;
    }

    cout << N - remain << endl;
}

