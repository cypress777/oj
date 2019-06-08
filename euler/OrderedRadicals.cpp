#include <iostream>
#include <vector>
#include <algorithm>
#include "../src/math_utils.hpp"

using namespace std;

int MM = 100001;

int get_rad(int n, const vector<int> &tab) {
    if (n == 1) return 1;

    int rad = 1;
    for (int p : tab) {
        if (p * p > n) break;
        if (n % p != 0) continue;

        rad *= p;
        while (n % p == 0) {
            n /= p;
        }
    }
    if (n > 1) rad *= n;
    return rad;
}

struct Rad {
    int id, rad;
    Rad(int i, int r) : id(i), rad(r) {}
};

bool comp(Rad a, Rad b) {
    if (a.rad == b.rad) return a.id < b.id;
    return a.rad < b.rad;
}

int main() {
    vector<int> prime_tab;
    gen_prime_tab(MM, prime_tab);

    vector<Rad> rads;
    for (int n = 1; n <= MM; n++) {
        int rad = get_rad(n, prime_tab);
        rads.push_back(Rad(n, rad));
    }

    sort(rads.begin(), rads.end(), comp);

    cout << rads[10000 - 1].id << " " << rads[10000 - 1].rad << endl;

    return 0;
}

