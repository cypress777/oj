#include "math_utils.hpp"

void gen_prime_tab(int n, std::vector<int> &prime_tab) {
    int count = 0;
    auto is_prime = std::vector<int>(n + 1, 1);
    prime_tab = std::vector<int>{};

    for (int i = 2; i < n; i++) {
        if (is_prime[i] == 1) {
            prime_tab.push_back(i);
            count += 1;
        }

        for (int p : prime_tab) {
            if (p * i > n) break;
            is_prime[p * i] = 0;
            if (i % p == 0) break;
        }
    }
}