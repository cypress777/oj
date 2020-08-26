#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    string S;
    cin >> S;

    vector<int> sub_cnt(S.size() + 1, 0);
    for (int i = 3; i <= S.size(); i++) {
        if (i == 3) {
            sub_cnt[i] = 1;
        } else {
            sub_cnt[i] = sub_cnt[i - 1] + i - 2;
        }
    }

    int cnt = 0;
    int id = 0;
    int len = 0;
    long long tot = 0;

    while (id < S.size()) {
        len++;

        if (id > 0 && S[id] == S[id - 1]) {
            cnt++;
        } else {
            cnt = 1;
        }

        if (cnt == 3) {
            len--;
            if (len >= 3) tot += sub_cnt[len];

            cnt = 2;
            len = 2;
        }

        id++;
    }

    if (len >= 3) tot += sub_cnt[len];

    tot = tot + S.size() + (S.size() - 1);

    cout << tot << endl;

    return 0;
}

