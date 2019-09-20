#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

double B(int n) {
    int x = 1;
    while (pow(2, x) - 1 < n) x++;

    int last = n - (pow(2, x - 1) - 1);

    double res = 0;
    for (int i = 1; i < x; i++) {
        res += double(i) * double(pow(2, i - 1)) / double(n);
    }
    res += double(last) * double(x) / double(n);
    return res;
}

int main() {
    cout << std::setprecision(8) << B(6) << endl;

    return 0;
}
