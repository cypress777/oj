#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> vals;
vector<int> metrics;
int n, m;
int mm;
vector<vector<int>> res;

int set_bit(int num, int n) { return num |= 1UL << n; }

int clear_bit(int num, int n) { return num &= ~(1UL << n); }

void Solve() {
    res = vector<vector<int>>(n, vector<int>(mm, -1));
    for (int i = 0; i < n; i++) res[i][0] = 0;
    for (int i = 0; i < mm; i++) {
        metrics[0] 
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < mm; j++) {
        }
    }
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

        for (int i = 0; i < n; i++) {
            int v, s;
            cin >> v >> s;
            int mets = 0;
            for (int j = 0; j < s; j++) {
                int m;
                cin >> m;
                mets = set_bit(mets, m);
            }

            vals.emplace_back(v);
            metrics.emplace_back(mets);
        }

        Solve();
    }

    return 0;
}