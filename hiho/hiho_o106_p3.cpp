#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long MOD = 1e9 + 7;
int Len;
string S;

void get_len_tab(const string &s, vector<int> &len_tab) {
    size_t len = s.size();
    len_tab = vector<int>(len, 0);

    int j = 1;
    int next = len_tab[j - 1];

    while (j < len) {
        if (next == -1 || s[j] == s[next]) {
            len_tab[j] = next + 1;

            j++;
            next = len_tab[j - 1];
        } else {
            if (next > 0) next = len_tab[next - 1];
            else next = -1;
        }
    }
}

long long calc(const vector<vector<bool>> &repeat) {
    vector<long long> res(Len, 0);

    for (int i = 1; i < Len; i++) {
        if (repeat[0][i]) res[i] = 1;

        for (int j = i - 2; j > 0; j--) {
            if (repeat[j + 1][i]) {
                res[i] = (res[i] + res[j]) % MOD;
            }
        }
    }

    return res[Len - 1];
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> Len >> S;

        vector<vector<bool>> repeat(Len, vector<bool>(Len, false));

        for (int j = 0; j < Len; j++) {
            string s(S.begin() + j, S.end());
            vector<int> len_tab;

            get_len_tab(s, len_tab);

            for (int k = 1; k < len_tab.size(); k++) {
                int len = len_tab[k];
                int overlap = len - 1 - (k - len + 1) + 1;

                if (overlap >= 0 && overlap % (len - overlap) == 0) {
                    repeat[j][j + k] = true;
                }
            }
        }

//        cout << S << endl;
//        for (int j = 0; j < Len; j++) {
//            for (int k = 0; k < Len; k++) {
//                cout << repeat[j][k] << " ";
//            }
//            cout << endl;
//        }

        long long tot;
        tot = calc(repeat);
        cout << tot << endl;
    }

    return 0;
}
