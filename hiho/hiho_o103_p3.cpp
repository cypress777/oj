#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int n, m, k;
unordered_set<int> row;
unordered_set<int> col;

vector<int> r_start;
vector<int> r_end;
vector<int> c_start;
vector<int> c_end;
vector<int> res;

int main() {
    cin >> n >> m >> k;

    r_start = vector<int>(n, m);
    r_end = vector<int>(n, -1);
    c_start = vector<int>(m, n);
    c_end = vector<int>(m, -1);

    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r > c;
        row.insert(r);
        col.insert(c);

        r_start[r] = min(c, r_start[r]);
        r_end[r] = max(c, r_end[r]);
        c_start[c] = min(r, c_start[c]);
        c_end[c] = max(r, c_end[c]);
    }

    res = vector<int>(5, 0);

    for (int i : row) {
        if (r_start[i] < r_end[i]) {
            for (int j : col) {
                if (j < r_start[i] || j > r_end[i]) continue;
                if (c_start[j] < i && c_end[j] > i) {
                    res[4]++;
                }
            }
        }
    }

    return 0;
}