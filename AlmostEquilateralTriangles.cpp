#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// https://www.mathblog.dk/project-euler-94-almost-equilateral-triangles/

long MM = 1000000000;

int main() {
    long sum = 0;

    long x1 = 2, y1 = 1, n = 3;
    long x = 2, y = 1;
    while (true) {
        // b = a + 1
        long t3a = 2 * x - 1;
        long t3area = y * (x - 2);
        if (t3a + 1 > MM) break;
        if (t3area > 0 && t3a % 3 == 0 && t3area % 3 == 0) {
            cout << t3a / 3 << " " << t3a / 3 + 1 << " " << t3area / 3 << endl;
            sum += t3a + 1;
        }

        // b = a - 1
        t3a = 2 * x + 1;
        t3area = y * (x + 2);
        if (t3a - 1 > MM) break;
        if (t3area > 0 && t3a % 3 == 0 && t3area % 3 == 0) {
            cout << t3a / 3 << " " << t3a / 3 - 1 << " " << t3area / 3 << endl;
            sum += t3a - 1;
        }

        long nx, ny;
        nx = x1 * x + n * y1 * y;
        ny = x1 * y + y1 * x;
        x = nx;
        y = ny;
    }

    cout << sum << endl;
    return 0;
}
