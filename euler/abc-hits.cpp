#include <iostream>
#include <cmath>
#include "../src/math_utils.hpp"

using namespace std;

vector<int> prime_tab;

int gcd(int a, int b) {
    int t = 1;
    int m = max(a, b);
    int n = min(a, b);
    while (n != 0) {
        t = m % n;
        m = n;
        n = t;
    }
    return m;
}

long long get_rad(int n) {
    long long rad = 1;
    for (int i = 0; i < prime_tab.size(); i++) {
        int p = prime_tab[i];
        if (p * p > n) break;

        if (n % p == 0) rad *= p;
        while (n % p == 0) {
            n /= p;
        }
    }
    if (n > 1) rad *= n;
    return rad;
}

int main() {
    int mm = 120000;
//    int mm = 10000;

    gen_prime_tab(mm + 1, prime_tab);

    vector<long long> rad_result(mm + 1, -1);

    long long tot = 0;
    int cnt = 0;

    for (int c = 2; c < mm; c++) {
        if (rad_result[c] == -1) rad_result[c] = get_rad(c);
        if (rad_result[c] >= c) continue;

        for (int a = 1; a < (c + 1) / 2; a++) {
            if (gcd(a, c) != 1) continue;

            if (rad_result[a] == -1) rad_result[a] = get_rad(a);
            if (rad_result[a] * rad_result[c] >= c) continue;

            int b = c - a;
            if (rad_result[b] == -1) rad_result[b] = get_rad(b);
            if (rad_result[a] * rad_result[b] * rad_result[c] >= c) continue;

            tot += c;
            cnt++;
        }
    }

    cout << cnt << " " << tot << endl;
}

