#include <iostream>
#include "../src/math_utils.hpp"

using namespace std;

int N = 10;
vector<long long> prime_tab;

void cal(int pos, int cnt, long long val, int digit, int tot, long long &sum) {
    if (tot - cnt > N - pos) return;

    if (pos == N) {
        if (cnt == tot) {
            if (isPrime(val, prime_tab)) {
                cout << pos << " " << cnt << " " << val << " " << digit << " " << tot << " " << sum << endl;
                sum += val;
            }
        }
    } else {
        for (int i = 0; i <= 9; i++) {
            if (pos == 0 && i == 0) continue;

            long long new_val = val * 10 + i;

            int new_cnt = cnt;
            if (i == digit) new_cnt++;

            cal(pos + 1, new_cnt, new_val, digit, tot, sum);
        }
    }
}

int main() {
    long long res = 0;

    gen_prime_tab((long long)100000, prime_tab);

    for (int i = 0; i <= 9; i++) {
        for (int j = N; j >= 1; j--) {
            long long sum = 0;
            cal(0, 0, 0, i, j, sum);

            if (sum > 0) {
                res += sum;
                cout << i << "  " << j << " " << sum << endl;
                break;
            }
        }
    }

    cout << res << endl;

    return 0;
}

