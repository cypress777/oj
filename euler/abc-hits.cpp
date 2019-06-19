#include <iostream>
#include <cmath>
#include <unordered_map>
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

int get_rad(int n) {
    int rad = 1;
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
//    int mm = 1000;

    gen_prime_tab(mm + 1, prime_tab);

    unordered_map<int, int> rad_result;

    long long tot = 0;
    int cnt = 0;
    for (int a = 1; a <= mm / 2; a++) {
        for (int b = a + 1; b <= mm - a; b++) {
            int c = a + b;

            if (gcd(a, b) != 1) continue;

            int abc = a * b * c;
            if (rad_result.find(abc) == rad_result.end()) {
                if (rad_result.find(a) == rad_result.end()) rad_result[a] = get_rad(a);
                if (rad_result.find(b) == rad_result.end()) rad_result[b] = get_rad(b);
                if (rad_result.find(c) == rad_result.end()) rad_result[c] = get_rad(c);
                rad_result[abc] = rad_result[a] * rad_result[b] * rad_result[c];
            }

            if (rad_result[abc] < c) {
//                cout << a << " " << b << " " << c << endl;
                tot += c;
                cnt ++;
            }
        }
    }

    cout << cnt << " " << tot << endl;
}

