#include <iostream>
#include <cmath>
#include <vector>

#define PI acos(-1)

using namespace std;

double range_low = -0.01;
double range_high = 0.01;

struct Point {
    double x_, y_;
    Point(double x, double y) : x_(x), y_(y) {}
    explicit Point() {}
};

Point get_next_point(const Point &start, const Point &end) {
    double alpha = atan2(-4 * end.x_, end.y_);
    double beta = atan2(end.y_ - start.y_, end.x_ - start.x_);

    double k = tan(PI + 2 * alpha - beta);
    double t = end.y_ - k * end.x_;

    double a = 4 + k * k;
    double b = 2 * k * t;
    double c = t * t - 100;

    double x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    double x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    double y1 = k * x1 + t;
    double y2 = k * x2 + t;

    if (abs(x1 - end.x_) < 0.001 && abs(y1 - end.y_) < 0.001) {
        return Point(x2, y2);
    } else {
        return Point(x1, y1);
    }
}

int main() {
    Point last(0, 10.1);
    Point cur(1.4, -9.6);
    Point next = get_next_point(last, cur);

    int cnt = 1;

    while (next.y_ < 0 || next.x_ < range_low || next.x_ > range_high) {
        cnt++;
        last = cur;
        cur = next;
        next = get_next_point(last, cur);
    }

    cout << cnt << endl;

    return 0;
}

