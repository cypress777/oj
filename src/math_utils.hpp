#pragma once

#include <vector>

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

template <typename T>
bool isPrime(T n, const std::vector<T> &prime_tab) {
    for (T p : prime_tab) {
        if (n % p == 0) return false;
        if (p * p > n) return true;
    }
}
