#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

double X, Y, H, D;

int main() {
    cin >> X >> Y >> H >> D;

    double p = 0;

    if (X >= H + D) {
        p = 1;
    } else if (X + Y < H) {
        p = 0;
    } else if (X + Y > H + D) {
        double sall = (Y + 1) * (D + 1);
        double l = max(X - H + 1, 1.0);
        double r = D;
        double s1 = (l + r) * (r - l + 1) / 2.0;
        double s2 = (Y - (H + D - X) + 1) * (D + 1);
        p = (s1 + s2) / sall;
    } else if (X + Y <= H + D) {
        double sall = (Y + 1) * (D + 1);
        double l = max(X - H + 1, 1.0);
        double r = X + Y - H + 1;
        double s = (l + r) * (r - l + 1) / 2.0;
        p = s / sall;
    }

    printf("%.2f\n", p);
    return 0;
}
