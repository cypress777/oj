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

    // fs[i][j]: amount of number se than j in seq[1 : i]
    // fl[i][j]: amount of number le than j in seq[1 : i]
    // bs[i][j]: amount of number se than j in seq[i : n]
    // bl[i][j]: amount of number le than j in seq[i : n]

    fs = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));
    fl = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));
    bs = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));
    bl = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n + 1; j++) fs[i][j] = fs[i - 1][j] + seq[i] <= j ? 1 : 0;
        for (int j = 0; j <= n + 1; j++) fl[i][j] = fl[i - 1][j] + seq[i] >= j ? 1 : 0;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= n + 1; j++) bs[i][j] = bs[i + 1][j] + seq[i] <= j ? 1 : 0;
        for (int j = 0; j <= n + 1; j++) bl[i][j] = bl[i + 1][j] + seq[i] >= j ? 1 : 0;
    }

    int res = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n + 1; j++) {
            res = max(res, fs[i][j] + fl[i][j + 1] + bs[i + 1][j] + bl[i + 1][j + 1]);
            cout << "-----------" << i << " " << j << " " << res << endl;
            cout << fs[i][j] << " " << fl[i][j + 1] << endl;
            cout << bs[i + 1][j] << " " << bl[i + 1][j + 1] << endl;
        }
    }
    cout << res << endl;

    return 0;
}