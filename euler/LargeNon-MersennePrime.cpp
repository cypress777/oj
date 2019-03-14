#include <iostream>

using namespace std;

// (28433×2^7830457+1) % 10000000000
long long MM = 10000000000;

int main() {
    long long res = 1;
    for (int i = 0; i < 7830457; i++) res = res * 2 % MM;
    res = 28433 * res % MM;
    res = (res + 1) % MM;

    cout << res << endl;

    return 0;
}