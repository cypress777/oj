#include <iostream>
#include <vector>

using namespace std;

long long MM = 1000000007;

vector<vector<long long>> sum_lut;
vector<vector<long long>> cnt_lut;

int get_len(long long n) {
    int len = 0;
    while(n > 0) len++, n /= 10;
    return len;
}

long long mult_pow10(long long n, int t) {
    for (int i = 0; i < t; i++) n = (n * 10) % MM;
    return n;
}

vector<int> get_digits(long long n) {
    vector<int> digits;
    string s = to_string(n);
    for (int ss : s) digits.push_back(ss - '0');
    return digits;
}

void dfs(int k, int pos, vector<int> digits, long long &tot) {
    int len = digits.size() - pos;
    if (len < 1) return;

    long long high = 0;
    for (int i = 0; i < pos; i++) high = (high * 10 + digits[i]) % MM;
//        cout << "------" << endl;
//        cout << "-> " << k << " " << pos << " " << tot << " " << high << endl;

    for (int i = 0; i <= digits[pos]; i++) {
        if (i - k < -81 || i - k > 81) continue;

        if (pos == 0 && i == 0) continue;

        if (pos != digits.size() - 1 && i == digits[pos]) continue;

        long long tail = sum_lut[len - 1][i - k + 100] % MM;

        long long top = (high * 10 + i) % MM;
        top = cnt_lut[len - 1][i - k + 100] * top % MM;
        top = mult_pow10(top, len - 1);

        tot = (tot + tail + top) % MM;

//        cout << pos << " " << digits[pos] << " " << len << " " << tail << " " << top << " " << tot << endl;
    }

    dfs(digits[pos] - k, pos + 1, digits, tot);
}

long long cal(int k, long long limit) {
    if (limit <= 0) return 0;
    long long res = 0;

    int length = get_len(limit);

    for (int len = 1; len < length; len++) {
        for (int i = 1; i <= 9; i++) {
            if (i - k < -81 || i - k > 81) continue;

            long long tail = sum_lut[len - 1][i - k + 100] % MM;

            long long top = cnt_lut[len - 1][i - k + 100] * i % MM;
            top = mult_pow10(top, len - 1);

            res = (res + tail + top) % MM;
        }
    }
//    cout << res << endl;

    long long tot = 0;
    dfs(k, 0, get_digits(limit), tot);
//    cout << "=== tot: " << tot << endl;

    res = (res + tot) % MM;

    return res;
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

    long long res = 0;
//    res = cal(k, r);
////    cal(k, l);
//
//    cout << res << endl;
//    return 0;

    res = (MM + cal(k, r) - cal(k, l - 1)) % MM;

    cout << res << endl;

    return 0;
}
