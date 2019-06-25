#include <iostream>
#include <vector>

using namespace std;

long long MM = 1000000007;

vector<vector<long long>> sum_lut;
vector<vector<long long>> cnt_lut;

void cal(int k, long long l, long long r, long long &res, long long &cnt);
void cal_same(int len, int k, long long limit_min, long long limit_max, long long &res, long long &cnt);

int get_len(long long n) {
    int len = 0;
    while(n > 0) len++, n /= 10;
    return len;
}

long long mult_pow10(long long n, int t) {
    for (int i = 0; i < t; i++) n = (n * 10) % MM;
    return n;
}

void cal(int k, long long l, long long r, long long &res, long long &cnt) {
    int len_min = get_len(l), len_max = get_len(r);

    if (len_min == len_max) {
        cal_same(len_min, k, l, r, res, cnt);
    } else {
        cal_same(len_min, k, l, mult_pow10(1, len_min) - 1, res, cnt);
        cal_same(len_max, k, mult_pow10(1, len_max - 1), r, res, cnt);

        for (int len = len_min + 1; len < len_max; len++) {
            cal_same(len, k, mult_pow10(1, len - 1), mult_pow10(10L, len) - 1, res, cnt);
        }
    }
}

void cal_same(int len, int k, long long limit_min, long long limit_max, long long &res, long long &cnt) {
    cout << len << " " << k << " " << limit_min << " " << limit_max << endl;
    if (len < 1) return;
    if (len == 1) {
        if (k >= limit_min && k <= limit_max) {
            res++;
            cnt++;
        }
        return;
    }

    for (int i = limit_min / mult_pow10(1, len - 1) + 1; i <= limit_max / mult_pow10(1, len - 1); i++) {
        if (i - k < -100 || i - k > 100) break;

        long long tail = sum_lut[len - 1][i - k + 100] % MM;

        long long top = cnt_lut[len - 1][i - k + 100] * i % MM;
        mult_pow10(top, len - 1);

        res = (res + tail + top) % MM;
    }

    long long lmin_top = limit_min / mult_pow10(1, len - 1), lmax_top = limit_max / mult_pow10(1, len - 1);

    long long lmin_rear = limit_min % mult_pow10(1, len - 1), lmax_rear = limit_max % mult_pow10(1, len - 1);

    int lmin_rear_len = get_len(lmin_rear), lmax_rear_len = get_len(lmax_rear);

    if (lmin_top == lmax_top) {
        long long tail_sum = 0, tail_cnt = 0;

        cal(k - lmin_top, lmin_rear, lmax_rear, tail_sum, tail_cnt);

        long long top_sum = tail_cnt * lmin_top % MM;
        mult_pow10(top_sum, len - 1);

        res = (res + tail_sum + top_sum) % MM;
    } else {
        long long lmin_tail_sum = 0, lmin_tail_cnt = 0;

        cal(k - lmin_top, lmin_rear, mult_pow10(1, len - 1) - 1, lmin_tail_sum, lmin_tail_cnt);

        long long lmin_top_sum = lmin_tail_cnt * lmin_top % MM;
        mult_pow10(lmin_top_sum, len - 1);

        res = (res + lmin_tail_sum + lmin_top_sum) % MM;

        long long lmax_tail_sum = 0, lmax_tail_cnt = 0;
        cal(k - lmax_top, lmax_rear, mult_pow10(1, len - 1) - 1, lmax_tail_sum, lmax_tail_cnt);

        long long lmax_top_sum = lmax_tail_cnt * lmax_top % MM;
        mult_pow10(lmax_top_sum, len - 1);

        res = (res + lmax_tail_sum + lmax_top_sum);
    }
}

int main() {
    long long l, r, k;
    cin >> l >> r >> k;

    sum_lut = vector<vector<long long>>(20, vector<long long>(201, 0));
    cnt_lut = vector<vector<long long>>(20, vector<long long>(201, 0));
    cnt_lut[0][100] = 1;

    // len
    for (int i = 1; i <= 18; i++) {
        // sum
        int sign = (i % 2 == 1 ? 1 : -1);
        for (int j = -100; j <= 100; j++) {
            for (int n = 0; n <= 9; n++) {
                if (j - sign * n > 100 || j - sign * n < -100) continue;

                sum_lut[i][j + 100] = (sum_lut[i][j + 100] + sum_lut[i - 1][j - sign * n + 100] * 10 % MM + n * cnt_lut[i - 1][j - sign * n + 100]) % MM;
                cnt_lut[i][j + 100] = (cnt_lut[i][j + 100] + cnt_lut[i - 1][j - sign * n + 100]) % MM;
            }
        }
    }

    int len_min = get_len(l), len_max = get_len(r);

    long long res = 0;
    long long cnt = 0;
    cal(k, l, r, res, cnt);

    cout << res << endl;

    return 0;
}