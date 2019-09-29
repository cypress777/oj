#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

long long pow_10(int power, long long mod) {
    long long res = 1;
    for (int i = 1; i <= power; i++) {
        res = (res * 10) % mod;
    }
    return res;
}

int main() {
    string sn;
    cin >> sn;

    long long X, Y;
    cin >> X >> Y;

    if (sn == "?") {
        if (Y < 10) cout << Y << endl;
        else cout << "No solution" << endl;
        return 0;
    }

    long long base_rem = 0;
    for (int i = 0; i < sn.size(); i++) {
        if (sn[i] == '?') {
            if (i == 0) {
                base_rem = 1;
                continue;
            }

            base_rem = (base_rem * 10) % X;
        } else {
            base_rem = (base_rem * 10 + sn[i] - '0') % X;
        }
    }
//    cout << base_rem << endl;

    vector<int> places;
    for (int i = 0; i < sn.size(); i++) {
        if (sn[i] == '?') {
            places.push_back(i);
        }
    }

    vector<vector<int>> flg(places.size() + 1, vector<int>(X, 0));
    vector<vector<int>> ans(places.size() + 1, vector<int>(X, 0));
    flg[places.size()][base_rem] = 1;

    for (int i = places.size() - 1; i >= 0; i--) {
        int start = 0, end = 10;
        if (places[i] == 0) start = 1;

        for (int j = 0; j < X; j++) {
            for (int d = start; d < end; d++) {
                if (flg[i + 1][(j - (d * pow_10(sn.size() - 1 - places[i], X)) % X + X) % X] == 1) {
                    ans[i][j] = d;
                    flg[i][j] = 1;
//                    cout << i << " " << places[i] << " " << j << " " << (j - (d * pow_10(sn.size() - 1 - places[i], X)) % X + X) % X << endl;
                    break;
                }
            }
        }
    }

//    for (int i = 0; i < flg.size(); i++) {
//        for (int j = 0; j < flg[i].size(); j++) {
//            cout << flg[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    cout << endl;
//    for (int i = 0; i < ans.size(); i++) {
//        for (int j = 0; j < ans[i].size(); j++) {
//            cout << ans[i][j] << " ";
//        }
//        cout << endl;
//    }


    if (flg[0][Y] == 1) {
        string res = sn;
        long long rem = Y;

        for (int i = places.size() - 1; i >= 0; i--) {
            res[places[i]] = ans[i][rem] + '0';
            rem = (rem - (ans[i][rem] * pow_10(sn.size() - 1 - places[i], X)) % X + X) % X;
        }

        cout << res << endl;
    } else {
        cout << "No solution" << endl;
    }

    return 0;
}