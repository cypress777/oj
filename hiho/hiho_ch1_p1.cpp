#include <iostream>
#include <vector>

using namespace std;

long long MM = 1000000007;

vector<vector<long long>> sum_lut;
vector<vector<long long>> cnt_lut;

long long mod_pow(long long base, long long power) {
    long long res = 1, num = base;
    while (power > 0) {
        if (power % 2 == 1) res = (res * num) % MM;
        num = (num * base) % MM;
        power /= 2;
    }
}

long long mult_pow10(long long n, int t) {
    for (int i = 0; i < t; i++) n = (n * 10) % MM;
    return n;
}

void cal(int len, int k, long long limit_min, long long limit_max, long long &res, long long &cnt) {
    if (len == 1) {
        if (k >= limit_min && k <= limit_max) {
            res++;
            cnt++;
        }
        return;
    }

    for (int i = limit_min / pow(10, len - 1) + 1; i <= limit_max / pow(10, len - 1); i++) {
        if (i - k < -100 || i - k > 100) break;

        long long tail = sum_lut[len - 1][i - k]) % MM;

        long long top = cnt_lut[len - 1][i - k] * i % MM;
        mult_pow10(top, len - 1);

        res = (res + tail + top) % MM;
    }

    long long lmin_top = limit_min / pow(10L, len - 1), lmax_top = limit_max / pow(10L, len - 1);
    long long lmin_rear = limit_min % pow(10L, len - 1), lmax_rear = limit_max % pow(10L, len - 1);
    if (lmin_top == lmax_top) {
        long long tail_sum = 0, tail_cnt = 0;
        cal(len - 1, lmin_top - k, lmin_rear, lmax_rear, tail_sum, tail_cnt);

        long long top_sum = tail_cnt * lmin_top % MM;
        mult_pow10(top_sum, len - 1);

        res = (res + tail_sum + top_sum) % MM;
    } else {
        long long lmin_tail_sum = 0, lmin_tail_cnt = 0;
        cal(len - 1, lmin_top - k, lmin_rear, pow(10L, len - 1) - 1, lmin_tail_sum, lmin_tail_cnt);

        long long lmin_top_sum = lmin_tail_cnt * lmin_top % MM;
        mult_pow10(lmin_top_sum, len - 1);

        res = (res + lmin_tail_sum + lmin_top_sum) % MM;

        long long lmax_tail_sum = 0, lmax_tail_cnt = 0;
        cal(len - 1, lmin_top - k, lmin_rear, pow(10L, len - 1) - 1, lmax_tail_sum, lmax_tail_cnt);

        long long lmax_top_sum = lmax_tail_cnt * lmax_top % MM;
        mult_pow10(lmax_top_sum, len - 1);

        res = (res + lmax_tail_sum + lmax_top_sum);
    }
}

int main() {
    long long l, r, k;
    cin >> l >> r >> k;

    sum_lut = vector<vector<long long>>(10, vector<long long>(201, 0));
    cnt_lut = vector<vector<long long>>(10, vector<long long>(201, 0));
    cnt_lut[0][0] = 1;

    // len
    for (int i = 1; i <= 9; i++) {
        // sum
        int sign = (j % 2 == 1 ? 1 : -1);

        for (int j = -100; j <= 100; j++) {
            for (n = 0; n <= 9; n++) {
                if (j - sign * n > 100 || j - sign * n < -100) break;
                sum_lut[i][j] = (sum_lut[i][j] + sum_lut[i - 1][j - sign * n] * 10 % MM + n * cnt_lut[i - 1][j - sign * n]) % MM;
                cnt_lut[i][j] = (cnt_lut[i][j] + cnt_lut[i - 1][j - sign * n]) % MM;
            }
        }
    }

    int len_min = 0, len_max = 0;

    int ll = l;
    while (ll > 0) len_min++, ll /= 10;

    int rr = r;
    while (rr > 0) len_max++, rr /= 10;

    long long res = 0;
    long long cnt = 0;
    if (len_min == len_max) {
        cal(len_min, k, l, r, res, cnt);
    } else {
        cal(len_min, k, l, pow(10L, len_min) - 1, res, cnt);
        cal(len_max, k, pow(10L, len_max - 1), r, res, cnt);

        for (int len = len_min + 1; len < len_max; len++) {
            res + cal(len, k, pow(10L, len - 1), pow(10L, len) - 1, res, cnt);
        }
    }

    cout << res << endl;

    return 0;
}

