#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

double B(long long n) {
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

double R(long long n) {
    double res = 0;
    for (long long i = 0; i < n; i++) {
        double exp = 0;
        cout << "--- " << i << endl;

        if (i == 0 || i == n - 1) {
            exp = ((B(n - 1) + 1.0) * double(n - 1.0) + 1.0) / double(n);
            cout << B(n - 1) << " " << exp << endl;
        } else {
            exp = ((B(i) + 1.0) * double(i) + (B(n - 1 - i) + 1.0) * (n - 1 - i) + 1.0) / double(n);
            cout << B(i) << " " << B(n - 1 - i) << " " << exp << endl;
        }

        res += exp;
    }

    res /= double(n);

    return res;
}

int main() {
    cout << std::setprecision(8) << B(6) << endl;
    cout << R(6) << endl;

    return 0;
}
