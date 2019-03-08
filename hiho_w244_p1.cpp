#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> vals;
vector<int> metrics;
int n, m;
unsigned long mm;
vector<vector<int>> res;

unsigned long set_bit(unsigned long num, int n) { return num |= 1UL << n; }

unsigned long clear_bit(unsigned long num, int n) { return num &= ~(1UL << n); }

void Solve() {
    res = vector<vector<int>>(n, vector<int>(mm + 1, 0));
    for (int i = 0; i < n; i++) res[i][0] = 0;
    res[0][metrics[0]] = vals[0];
    for (int i = 0; i <= mm; i++) cout << res[0][i] << " ";
    cout << endl;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= mm; j++) {
            res[i][j] = max(res[i - 1][j & (~metrics[i])] + vals[i], res[i - 1][j]);
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    cout << res[n - 1][mm] << endl;
}

int main() {
    int T;
    cin >> T;

    for (int k = 0; k < T; k++) {
        vals = vector<int>{};
        metrics = vector<int>{};
        mm = 0;

        cin >> n >> m;
        for (int i = 0; i < m; i++) mm = set_bit(mm, i);
        // cout << mm << endl;

        for (int i = 0; i < n; i++) {
            int v, s;
            cin >> v >> s;
            unsigned long mets = 0;
            for (int j = 0; j < s; j++) {
                int m;
                cin >> m;
                mets = set_bit(mets, m - 1);
            }

            vals.emplace_back(v);
            metrics.emplace_back(mets);
            // cout << i << " " << v << " " << mets << endl;
        }

        Solve();
    }

    return 0;
}