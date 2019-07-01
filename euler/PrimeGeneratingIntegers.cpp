#include "../src/math_utils.hpp"

#include <iostream>
#include <cmath>

using namespace std;

long long MM = 100000000;
//long long MM = 100;
vector<long long> ptab;

void calc(long long len, long long pos, long long val, long long &res) {
    for (long long i = pos + 1; i < ptab.size(); i++) {
        if (ptab[i] * val > MM) break;

        long long new_val = val * ptab[i];

        if (isPrime(new_val + 1, ptab)) {
            calc(len + 1, i, new_val, res);
            res += new_val;
//            cout << len << " " << new_val << " " << res << endl;
        }
    }
}

int main() {
    gen_prime_tab(MM, ptab);
    cout << ptab.size() << endl;

    long long res = 0;
    calc(0, -1, 1, res);

    res += 1;

    cout << res << endl;

    return 0;
}

