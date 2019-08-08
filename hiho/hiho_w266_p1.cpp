#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using  namespace std;

double PI = 3.1415926;
int N, R;

struct Point {
    int x_, y_;
    Point(int x, int y) : x_(x), y_(y) {}
};

struct Edge {
    double v_;
    int sign_;

    explicit Edge() {}
    Edge(double v, int sign) : v_(v), sign_(sign) {}
};

bool get_range(const Point &a, const Point &b, Edge &l, Edge &r) {
    double dist = sqrt(pow(b.y_ - a.y_, 2) + pow(b.x_ - a.x_, 2));
    if (dist > 2 * R) return false;

    if (a.x_ == b.x_ && a.y_ == b.y_) {
        l = Edge(0, 1);
        r = Edge(2 * PI, -1);
        return true;
    }

    double theta = atan2(b.y_ - a.y_, b.x_ - a.x_); // [-pi, pi]

    double theta_offset = acos(dist / 2.0 / R); // [0, pi]

    l = Edge(theta - theta_offset, 1);
    r = Edge(theta + theta_offset, -1);

//    cout << a.x_ << " " << a.y_ << " " << b.x_ << " " << b.y_ << " " << l.v_ << " " << r.v_ << endl;
    return true;
}

bool comp(Edge a, Edge b) {
    if (a.v_ == b.v_) return a.sign_ == 1;
    return a.v_ < b.v_;
}

int count(vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), comp);

    int res = 0;
    int cur = 0;
    for (int i = 0; i < edges.size(); i++) {
        cur += edges[i].sign_;
        res = max(res, cur);
    }

    return res;
}

int main() {
    cin >> N >> R;

//    Edge l, r;
//    get_range(Point(5, 10), Point(9, 10), l, r);
//    return 0;

    vector<Point> cords;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        cords.push_back(Point(x, y));
    }

    int max_count = 0;
    for (int i = 0; i < N; i++) {
        vector<Edge> edges;

        for (int j = 0; j < N; j++) {
            if (i == j) continue;

            Edge l, r;
            if (get_range(cords[i], cords[j], l, r)) {
                edges.push_back(l);
                edges.push_back(r);
            }
        }

        int covered = count(edges) + 1;

        max_count = max(max_count, covered);
    }

    cout << max_count << endl;

    return 0;
}

