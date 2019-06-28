#include <iostream>
#include <vector>
#include <unordered_set>
#include "../src/math_utils.hpp"

using namespace std;

long long MM = 1000000;
vector<long long> primes;

long long calc(long long tot, long long out) {
    if (tot == 0 && out == 0) return 1;

    long long len = min(out, tot - out);

    long long res = 1;
    for (long long i = 0; i < len; i++) {
        res = res * (tot - i) / (i + 1);
    }

    return res;
}

bool is_free(long long n) {
    for (long long p : primes) {
        if (p * p > n) break;

        int cnt = 0;
        while (n % p == 0) {
            cnt++;
            if (cnt > 1) return false;
            n /= p;
        }
    }

    return true;
}

int main() {
    gen_prime_tab(MM, primes);

    int cnt = 0;
    long long res = 0;
    unordered_set<long long> ans;

    for (int i = 1; i <= 51; i++) {
        for (int j = 1; j <= (i + 1) / 2; j++) {
            long long val = calc(i - 1, j - 1);

            if (ans.find(val) == ans.end()) {
                ans.insert(val);

                if (is_free(val)) {
                    cnt++;
                    res += val;
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}

