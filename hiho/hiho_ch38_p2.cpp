#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> fs;
vector<vector<int>> fl;
vector<vector<int>> bs;
vector<vector<int>> bl;
vector<int> seq;

int main() {
    cin >> n;
    seq = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> seq[i];
    }

    fs = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));
    fl = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));
    bs = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));
    bl = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fs[i][j] = fs[i - 1][j];
            fl[i][j] = fl[i - 1][j];
        }
        for (int j = seq[i]; j <= n; j++) fs[i][j] = max(fs[i][j], fs[i - 1][seq[i] - 1] + 1);
        for (int j = seq[i]; j >= 1; j--) fl[i][j] = max(fl[i][j], fl[i - 1][seq[i] + 1] + 1);
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            bs[i][j] = bs[i + 1][j];
            bl[i][j] = bl[i + 1][j];
        }
        for (int j = seq[i]; j <= n; j++) bs[i][j] = max(bs[i][j], bs[i + 1][seq[i] - 1] + 1);
        for (int j = seq[i]; j >= 1; j--) bl[i][j] = max(bl[i][j], bl[i + 1][seq[i] + 1] + 1);
    }

    // for (int i = 0; i <= n + 1; i++) {
    //     for (int j = 0; j <= n + 1; j++) {
    //         cout << "fs: " << i << " " << j << " " << fs[i][j] << endl;
    //         cout << "fl: " << i << " " << j << " " << fl[i][j] << endl;
    //         cout << "bs: " << i << " " << j << " " << bs[i][j] << endl;
    //         cout << "bl: " << i << " " << j << " " << bl[i][j] << endl;
    //     }
    // }
    // return 0;

    int res = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            res = max(res, fs[i][j] + fl[i][j + 1] + bs[i + 1][j] + bl[i + 1][j + 1]);
        }
    }
    cout << res << endl;
 
    return 0;
}