#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

double err = 10e-8;

struct Point {
    double x, y;
    Point() {};
    Point(double x_, double y_) : x(x_), y(y_) {}
};

bool comp(const Point &a, const Point &b) {
    return a.x > b.x;
}

bool on_line(const Point &a, const Point &b, const Point &c) {
    return fabs((b.y - a.y) * (c.x - a.x) - (c.y - a.y) * (b.x - a.x)) < err;
}

vector<Point> points;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        points.emplace_back(Point(x, y));
    }

    sort(points.begin(), points.end(), comp);

    vector<Point> line_a(1, points[0]);
    vector<Point> line_b{};

    int find_a = false;
    int i = 1, j = 1;
    while (i < points.size()) {
        if (fabs(points[i].x - points[i - 1].x) < err && fabs(points[i].y - points[i - 1].y) < err) {
            i++;
            continue;
        }
        for (j = i + 1; j < points.size(); j++) {
            if (fabs(points[j].x - points[j - 1].x) < err && fabs(points[j].y - points[j - 1].y) < err) continue;
            if (on_line(line_a[0], points[i], points[j])) {
                if (!find_a) {
                    find_a = true;
                    line_a.emplace_back(points[i]);
                    for (int k = i + 1; k < j; k++) {
                        line_b.emplace_back(points[k]);
                    }
                }
                line_a.emplace_back(points[j]);
            } else {
                if (find_a) line_b.emplace_back(points[j]);
            }
        }
        if (!find_a) {
            i++;
        } else {
            break;
        }
    }

    double a1 = 0, a2 = 0, b1 = 0, b2 = 0;
    for (int i = 1; i < line_a.size(); i++) {
        a1 += (line_a[i].y - line_a[i - 1].y) / (line_a[i].x - line_a[i - 1].x);
    }
    a1 /= (line_a.size() - 1.0);
    for (int i = 0; i < line_a.size(); i++) {
        b1 += (line_a[i].y - line_a[i].x * a1);
    }
    b1 /= line_a.size();

    for (int i = 1; i < line_b.size(); i++) {
        a2 += (line_b[i].y - line_b[i - 1].y) / (line_b[i].x - line_b[i - 1].x);
    }
    a2 /= (line_b.size() - 1.0);
    for (int i = 0; i < line_b.size(); i++) {
        b2 += (line_b[i].y - line_b[i].x * a2);
    }
    b2 /= line_b.size();

    if (a1 > a2) {
        cout << fixed << setprecision(1) << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
    } else {
        cout << fixed << setprecision(1) << a2 << " " << b2 << " " << a1 << " " << b1 << endl;
    }
}