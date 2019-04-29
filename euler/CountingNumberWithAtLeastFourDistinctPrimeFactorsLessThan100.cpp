#include <vector>
#include <iostream>
#include <cmath>
#include "../src/math_utils.hpp"

using namespace std;

int N;
long long MM;
vector<int> prime_tab;

long long combination(int n, int m) {
    if (m == n) return 1;

    long long a = 1, b = 1;
    m = min(n - m, m);

    for (int i = 1; i <= n; i++) {
        if (i <= m) a *= i;
        if (i > n - m) b *= i;
    }

    return b / a;
}

long long cal(int n, const std::vector<int> &id) {
    long long total = 0;
    long long factor = 1;
    if (!id.empty()) {
        for (int i = 0; i < id.size(); i++) {
            factor *= prime_tab[id[i]];
            if (factor > MM) return 0;
        }
    }

    if (id.size() == n) {
        return MM / factor;
    } else {
        int start = id.empty() ? 0 : id[id.size() - 1] + 1;
        for (int i = start; i <= N; i++) {
            if (id.size() + (N - i + 1) <= n) break;
            auto new_id = id;
            new_id.push_back(i);
            total += cal(n, new_id);
        }
        return total;
    }
}

int main() {
    gen_prime_tab(100, prime_tab);

    N = prime_tab.size();
    MM = 1e16;
//    MM = 1000;

    vector<long long> lambda(26, 0);
    lambda[4] = 1;

    for (int i = 5; i <= N; i++) {
        int repeated = 0;
        for (int j = 4; j < i; j++) {
            repeated += lambda[j] * combination(i, j);
        }
        lambda[i] = 1 - repeated;
    }

    long long total = 0;
    for (int i = 4; i <= N; i++) {
        long long var = cal(i, {});
        total += lambda[i] * var;
        cout << lambda[i] << " " << var << " " << total << endl;
    }

    cout << total << endl;

    return 0;
}