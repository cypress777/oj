#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long MOD = 1e9 + 7;

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

long long calc(const vector<vector<bool>> &repeat, ) {

}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int Len;
        string S;
        cin >> Len >> S;

        long long tot = 0;
        vector<vector<bool>> repeat(Len, vector<bool>(Len, false));

        for (int j = 0; j < Len; j++) {
            string s(S.begin() + j, S.end());
            vector<int> len_tab;

//            cout << "---- " << j << endl;
//            cout << s << endl;
//
            get_len_tab(s, len_tab);
//            for (auto l : len_tab) cout << l << " ";
//            cout << endl;

            for (int k = 1; k < len_tab.size(); k++) {
                int len = len_tab[k];
                int overlap = len - 1 - (k - len + 1) + 1;

                if (overlap == 0 || (overlap > 0 && len % overlap == 0)) {
                    repeat[j][j + k] = true;
                }
            }
        }

        for (int j = 0; j < Len; j++) {
            for (int k = 0; k < Len; k++) {
                cout << repeat[j][k] << " ";
            }
            cout << endl;
        }

        calc(repeat);
    }

    return 0;
}
