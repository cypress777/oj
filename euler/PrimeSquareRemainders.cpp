#include "../src/math_utils.hpp"
#include <iostream>

using namespace std;

long long MM = 1000000;

int main() {
    vector<long long> tab;
    gen_prime_tab(MM, tab);

    for (long long i = 1; i <= MM; i++) {
        long long rem = 0;
        long long p = tab[i - 1];
        long long pp = p * p;
        long long b = (p - 1) % pp;
        long long c = (p + 1) % pp;

        for (long long j = 1; j < i; j++) {
            b = b * (p - 1) % pp;
            c = c * (p + 1) % pp;
        }

        if ((b + c) % pp > 10000000000L) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}

