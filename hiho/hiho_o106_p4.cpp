#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long N, K, x_rem;
vector<long long> ptab, ftab;

template<typename T>
void gen_prime_tab(T n, std::vector<T> &prime_tab) {
    long long count = 0;
    auto is_prime = std::vector<bool>(n + 1, true);
    prime_tab = std::vector<T>{};

    for (T i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime_tab.push_back(i);
            count += 1;
        }

        for (T p : prime_tab) {
            if (p * i > n) break;
            is_prime[p * i] = false;
            if (i % p == 0) break;
        }
    }
}

void get_factors(vector<long long> &ftab, const vector<long long> &ptab) {
    long long kk = K;
    for (auto p : ptab) {
        if (kk % p == 0) ftab.push_back(p);

        while (kk % p == 0) kk /= p;

        if (kk == 0) break;
    }
}

void calc(long long cnt, long long last_id, long long cur_cnt, long long cur_fct, long long &res) {
    if (cnt == cur_cnt) {
        long long n_f = (K + 1) / cur_fct;

        long long t = 1;
        while ((cur_fct * t) % 3 != x_rem) t++;

        long long n_rem = (K + 1) / 3 + ((K + 1) % 3 >= (x_rem + 1) ? 1 : 0);
        long long n_f_x = n_f / 3 + (n_f % 3 >= t ? 1 : 0);
        res += n_rem - n_f_x;
    } else {
        for (long long i = last_id + 1; i < ftab.size(); i++) {
            calc(cnt, i, cur_cnt + 1, cur_fct * ftab[i], res);
        }
    }
}

long long C(long long a, long long b) {
    long long res = 1;

    b = max(a - b, b);

    for (long long i = a; i > b; i--) res = res * i;

    for (long long i = a - b; i > 0; i--) res /= i;

    return res;
}

int main() {
    cin >> N;

    K = (N + 3) / 2;
    x_rem = 3 - K % 3;

    long long res = 0;

    if (N == 1) {
        res = 1;
    } else if (x_rem == 3) {
        res = 0;
    } else {
        gen_prime_tab(static_cast<long long>(sqrt(K + 1)), ptab);

        get_factors(ftab, ptab);
        if (ftab.size() == 0) ftab.push_back(K);

        for (long long i = 1; i <= ftab.size(); i++) {
            long long cur_res = 0;
            calc(i, -1, 0, 1, cur_res);

            long long sign = 1;
            long long cnt = 0;
            for (long long j = 1; j < i; j++) {
                cnt += sign * C(i, j);
                sign *= -1;
            }
            res += (1 - cnt) * cur_res;
        }
    }

    cout << res << endl;

    return 0;
}

