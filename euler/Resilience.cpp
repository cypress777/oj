#include <iostream>
#include "../src/math_utils.hpp"

using namespace std;

long long MM = 1000000;
long long dd = 94744, nn = 15499;
//long long dd = 10, nn = 4;
vector<long long> primes;

void get_factors(long long n, vector<long long> &factors) {
    for (long long p : primes) {
        if (p * p > n) break;

        if (n % p == 0) factors.push_back(p);

        while(n % p == 0) n /= p;
    }
    if (n > 1) factors.push_back(n);
}

long long phi(long long n) {
    vector<long long> factors;
    get_factors(n, factors);

    long long res = n;

    for (long long p : factors) {
        res = res / p * (p - 1);
    }

    return res;
}

int main() {
    gen_prime_tab(MM, primes);

    long long pred = 1;
    long long d = 1;
    int last_idx = -1;
    for (long long p : primes) {
        pred = d;
        d = d * p;
        last_idx++;

        long long cnt = phi(d);

        if (cnt * dd < (d - 1) * nn) {
            cout << d << " " << cnt << " " << (cnt * 1.0 / (d - 1.0)) << endl;
            break;
        }
    }

    cout << "up limit: " << d << endl;
    cout << "last p: " << primes[last_idx] << endl;

    long long res = d;

    for (int i = last_idx; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            long long curd = d / primes[i];

            while (curd < res) {
                long long cnt = phi(curd);

                if (cnt * dd < (curd - 1) * nn) {
                    res = min(res, curd);
                    cout << res << " " << curd << " " << cnt << " " << (cnt * 1.0 / (curd - 1.0)) << endl;
                    break;
                }

                curd *= primes[j];
            }
        }
    }

    return 0;
}
