#include <iostream>
#include <vector>

using namespace std;

int N, K, x_rem;
vector<int> ptab, fcts;

template <typename T>
void gen_prime_tab(T n, std::vector<T> &prime_tab) {
    int count = 0;
    auto is_prime = std::vector<bool>(n + 1, true);
    prime_tab = std::vector<T>{};

    for (T i = 2; i < n; i++) {
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

void get_factors(vector<int> &fcts, const vector<int> &ptab) {
    int nn = n;
    for (auto p : ptab) {
        if (nn % p == 0) fcts.push_back(p);

        while (nn % p == 0) nn /= p;

        if (nn == 0) break;
    }
}

void calc(int cnt, int last_id, int cur_cnt, int cur_fct, int &res) {
    if (cnt == cur_cnt) {
        int nf = (K + 1) / cur_fct;

        int t = 1;
        while ((cur_fct * t) % 3 != x_rem) t++;

        res += ((K + 1) / 3 + ((K + 1) % 3 >= (x_rem + 1) ? 1 : 0)) - nf / 3 + (nf % 3 >= t ? 1 : 0);
    } else {
        for (int i = last_id + 1; i < fcts.size(); i++) {
            calc(cnt, i, cur_cnt + 1, cur_fct * fcts[i], res);
        }
    }
}

int main() {
    cin >> N;

    K = (N + 3) / 2;
    x_rem = 3 - K % 3;

    int res = 0;

    if (x_rem == 3) {
        cout << res << endl;
    } else {
        gen_prime_tab(n, ptab);

        get_factors(fcts, ptab);

        int sign = 1;
        for (int i = 0; i < fcts.size(); i++) {
            int cur_res = 0;
            calc(i, -1, 0, 1, cur_res);

            res += sign * cur_res;
        }
    }

    return 0;
}

