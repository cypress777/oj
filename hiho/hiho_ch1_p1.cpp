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

long long cal(int len, int k) {
    int pos_len = (len + 1) / 2, neg_len = len / 2;

    for (int pos = k; pos <= pos_len * 9; pos++) {
        int neg = pos - k;

        long long pos_cnt = 0, pos_sum = 0;
        long long pos_base = 0;
        for (int i = 0; i < pos_len; i++) base = (base * 100 + 1) % MM;
        for (int n = 1; n <= 9; n++) {
            pos_sum = (pos_sum + sum_lut[pos_len - 1][pos - n] * mod_pow(pos_len - 1, MM - 2) * pos_base) % MM;
            pos_sum = pos_sum + n * cnt_lut[pos_len - 1][pos - n] * (pow(10, len - 1) % MM);
        }
    }
}

long long cal_less(int len, int k, int limit) {

}

long long cal_more(int len, int k, int limit) {

}

int main() {
    long long l, r, k;
    cin >> l >> r >> k;

    sum_lut = vector<vector<long long>>(10, vector<long long>(101, 0));
    cnt_lut = vector<vector<long long>>(10, vector<long long>(101, 0));
    for (int i = 0; i <= 9; i++) sum_lut[1][i] = i, cnt_lut[i][j] = 1;

    // len
    for (int i = 2; i <= 9; i++) {
        // sum
        for (int j = 0; j <= 100; j++) {
            for (k = 0; k <= 9; k++) {
                if (j - k < 0) break;
                sum_lut[i][j] = (sum_lut[i][j] + sum_lut[i - 1][j - k] + k * cnt_lut[i - 1][j - k]) % MM;
                cnt_lut[i][j] = (cnt_lut[i][j] + cnt_lut[i - 1][j - k]) % MM;
            }
        }
    }

    int len_min = 0, len_max = 0;

    int ll = l;
    while (ll > 0) len_min++, ll /= 10;

    int rr = r;
    while (rr > 0) len_max++, rr /= 10;

    long long res = 0;

    if (len_min == len_max) {
        res = (cal_more(len_min, k, l) + cal_less(len_max, k, r) - cal(len_max, k) + MM) / 2;
    } else {
        res = (cal_more(len_min, k, l) + cal_less(len_max, k, r)) % MM;
        for (int len = len_min + 1; len < len_max; len++) {
            res = (res + cal(len, k)) % MM;
        }
    }

    cout << res << endl;

    return 0;
}

