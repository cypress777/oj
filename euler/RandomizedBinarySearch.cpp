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
    double res = 1;
    for (long long i = 2; i <= n; i++) {
        res = double(i + 1) / double(i) * double(i - 1) / double(i) * res - double(i - 1) / double(i) * double(i - 1) / double(i) + 1;
    }

    return res;
}

int main() {
    long long MM = 7e8;
    double b = B(MM);
    cout << b << endl;
    double r = R(MM);
    cout << std::setprecision(10) << b << " " << r << " " << r - b << endl;

    return 0;
}
