#include <iostream>
#include <vector>

using namespace std;

long long MM = 1000000007;

void permutate(int val, int len, vector<int> cur_nums, int &cnt) {
    int cur_val = 0;
    for (int i = 0; i < cur_nums.size(); i++) cur_val += cur_nums[i];

    if (cur_val > val || cur_nums.size() > len || (len  - cur_nums.size()) * 9 < (val - cur_val)) return;

    if (cur_nums.size() == len) {
        if (cur_val == val) {
            int all_per = 1;
            while (len > 0) {
                all_per *= len;
                len--;
            }

            int repeat = 1;
            int per = 1;
            for (int i = 1; i < cur_nums.size(); i++) {
                if (cur_nums[i] == cur_nums[i - 1]) {
                    repeat++;
                    per *= repeat;
                }

                if (i == cur_nums.size() - 1 || cur_nums[i] != cur_nums[i - 1]) {
                    all_per /= per;
                    repeat = 1;
                    per = 1;
                }
            }

            cnt += all_per;
        }
        return;
    }

    for (int i = cur_nums[cur_nums.size() - 1]; i <= 9; i++) {
        vector<int> new_nums = cur_nums;
        new_nums.push_back(i);
        permutate(val, len, new_nums, tot, cnt);
    }
}

long long cal_less(long long limit, int len, int k) {

}

long long cal_more(long long limit, int len, int k) {

}

long long cal(int len, k) {
    int pos_len = (len + 1) / 2, neg_len = len / 2;
    long long pos_base = 0, neg_base = 0;

    for (int i = 0; i < neg_len; i++) neg_base = (neg_base * 100 + 1) % MM;

    pos_base = neg_base;

    if (pos_len == neg_len) {
        pos_base = (pos_base * 10) % MM;
    } else {
        neg_base = (neg_base * 10) % MM;
        pos_base = (pos_base * 100 + 1) % MM;
    }

    long long res = 0;

    for (int pos = k, neg = pos - k; pos <= pos_len * 9; pos++) {
        int pos_cnt = 0, neg_cnt = 0;
        permutate(pos, pos_len, {}, pos_cnt);
        permutate(neg, neg_len, {}, neg_cnt);

        long long pos_sum = 0, neg_sum = 0;
        pos_sum = pos * pos_cnt / pos_len * pos_base % MM;
        neg_sum = neg * neg_cnt / neg_len * neg_base % MM;

        res = res + ((pos * neg_cnt) % MM + (neg_sum * pos_cnt) % MM) % MM;
    }
}

int main() {
    long long l, r, k;
    cin >> l >> r >> k;

    int len_min = 0, len_max = 0;

    int ll = l;
    while (ll > 0) len_min++, ll /= 10;

    int rr = r;
    while (rr > 0) len_max++, rr /= 10;

    long long res = 0;
    if (len_min == len_max) {
        res = (cal_more(ll, len_min, k) + cal_less(rr, len_max, k) - cal(len_min, k) + MM) % MM / 2;
    } else {
        res = cal_more(ll, len_min, k);
        res = (res + cal_less(rr, len_max, k)) % MM;
        for (int i = len_min + 1; i < len_max; i++) {
            res = (res + cal(i, k)) % MM;
        }
    }

    cout << res << endl;

    return 0;
}

