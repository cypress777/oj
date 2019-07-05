#include "../src/math_utils.hpp"

#include <iostream>
#include <cmath>

using namespace std;

long long MM = 100000000;
//long long MM = 100;
vector<long long> ptab;

void calc(long long len, long long pos, long long val, long long &res, int &cnt) {
    for (long long i = pos + 1; i < ptab.size(); i++) {
        long long new_val = val * ptab[i];

        if (new_val > MM) break;

        if (new_val % 2 == 1) continue;

        bool valid = true;
        for (int v = 1; v <= sqrt(new_val); v++) {
            if (new_val % v != 0) continue;
            if (!isPrime(new_val / v + v, ptab)) {
                valid = false;
                break;
            }
        }

        if (valid) {
//            cout << cnt << " " << new_val << endl;
            res += new_val;
            cnt++;
        }

        calc(len + 1, i, new_val, res, cnt);
    }
}

int main() {
    gen_prime_tab(MM, ptab);
    cout << ptab.size() << endl;

    long long res = 2;
    int cnt = 1;
    calc(0, 0, 2, res, cnt);

    res += 1;

    cout << cnt << " " << res << endl;

    return 0;
}

