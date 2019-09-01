#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    string S;
    cin >> S;

    vector<long long> sub_cnt(S.size() + 1, 0);
    for (int i = 1; i <= S.size(); i++) {
        sub_cnt[i] = sub_cnt[i - 1] + i - 1;
    }

    int len = 1, cnt = 1, tot = S.size();
    char last = S[0];

    for (int i = 1; i < S.size(); i++) {
        len++;

        if (S[i] == last) {
            cnt++;

            if (cnt > 2) {
                tot += sub_cnt[len - 1];
//                cout << i << " " << cnt << " " << len << " " << sub_cnt[len - 1] << endl;

                cnt = 2;
                len = 2;
            }
        } else {
            cnt = 1;
            last = S[i];
        }

        if (i == S.size() - 1) {
            tot += sub_cnt[len];
//            cout << i << " " << cnt << " " << len << " " << sub_cnt[len - 1] << endl;
        }
    }

    cout << tot << endl;

    return 0;
}

