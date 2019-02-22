#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long xn = 3, yn = 1;
    while (xn + yn < 1000000000000) {
       long long xnn, ynn;
       xnn = 5 * xn + 2 * yn - 2;
       ynn = 2 * xn + yn - 1;
       xn = xnn;
       yn = ynn;
    }
    cout << xn << " " << yn << endl;

    return 0;
}