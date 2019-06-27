#include <iostream>
#include <cmath>
#include <unordered_map>
#include "../src/math_utils.hpp"

using namespace std;

//long long MM = 1000000000L;
long long MM = 1000000000L;
vector<long long> ptab;

bool is_factor(long long len, long long p) {
    unordered_map<long long, long long> seq;

    long long rem = 1, l = 1, loop_len = 0, loop_start = 0;
    seq[rem] = l;

    while (l < len) {
        rem = (rem * 10 + 1) % p;
        l++;

        if (seq.find(rem) == seq.end()) {
            seq[rem] = l;
        } else {
            loop_start = seq[rem];
            loop_len = l - loop_start;
            break;
        }
    }

    if (seq.find(0) != seq.end()) {
        if ((len - seq[0]) % loop_len == 0) return true;
    }
    return false;
}

int main() {
    gen_prime_tab(1000000L, ptab);
    cout << ptab.size() << endl;

    int cnt = 0;
    long long res = 0;
    for (long long p : ptab) {
        if (is_factor(MM, p)) {
            cnt++;
            res += p;
            cout << cnt << " " << p << " " << res << endl;
        }

        if (cnt == 40) break;
    }

    return 0;
}

