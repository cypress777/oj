#include <iostream>
#include <vector>

using namespace std;

long long MM = 100000000;

int a = 1777;
int b = 1855;

vector<long long> loop;
long long start, len;

long long fast_pow(long long base, long long power, long long MOD) {
    long long res = 1;
    long long mult = base;

    while(power > 0) {
        if (power % 2 == 1) res = (res * mult) % MOD;
        mult = (mult * mult) % MOD;
        power /= 2;
    }

    return res;
}

long long calc(long long n, long long k) {
    if (k == 1) return n;

    long long power = calc(n, k - 1);
    return loop[power % loop.size()];
}

int main() {
    int i = 1;
    long long val = a;
    while (true) {
        bool has = false;
        for (int j = 0; j < loop.size(); j++) {
            if (loop[j] == val) {
                start = j;
                len = loop.size() - j + 1;
                has = true;
            }
        }

        if (has) break;

        loop.push_back(val);

        i++;
        val = fast_pow(val, a, MM);
    }

    cout << start << " " << len << " " << loop[start] << endl;

    cout << calc(a, b) << endl;

    return 0;
}