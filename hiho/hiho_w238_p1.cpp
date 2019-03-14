#include <iostream>

using namespace std;

long long MOD = 1000000007;
int N, M;

long long fast_pow(int base, int power) {
    long long res = 1;
    for (long long b = base; power; b = b * b % MOD, power >>= 1) if (power & 1) res = res * b % MOD;
    return res;
}

long long hook(int n, int m) {
    return n + M - m;
}

long long factorial(int n) {
    long long res = 1;
    for (int i = 1; i <= n; i++) res = res * i % MOD;
    return res;
}

int main() {
    cin >> N >> M;

    long long fac = factorial(N * M);

    long long h = 1;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) h = h * hook(i, j) % MOD;

    // res = fac / h % MOD
    //     = fac * h^-1 % MOD
    //     = fac * pow(h, MOD - 2)
    long long res = fac * fast_pow(h, MOD - 2) % MOD;

    cout << res << endl;

    return 0;
}