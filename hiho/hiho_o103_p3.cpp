#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

long long n, m, k;
unordered_set<int> r_set;
unordered_set<int> c_set;
vector<int> r;
vector<int> c;
unordered_map<int, vector<int>> rows;
unordered_map<int, vector<int>> cols;

int main() {
    long long res1 = 0, res11 = 0, res2 = 0, res21 = 0, res22 = 0, res0 = 0, light_cnt = 0;

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int rr, cc;
        cin >> rr >> cc;

        light_cnt++;

        r_set.insert(rr);
        c_set.insert(cc);

        if (rows.find(rr) == rows.end()) {
            rows[rr] = {cc};
        } else {
            int has = false;
            for (int k : rows[rr]) if (k == cc) has = true;
            if (!has) rows[rr].push_back(cc);
        }
        if (cols.find(cc) == cols.end()) {
            cols[cc] = {rr};
        } else {
            int has = false;
            for (int k : cols[cc]) if (k == rr) has = true;
            if (!has) cols[cc].push_back(rr);
        }
    }

    for (int i : r_set) r.push_back(i);
    for (int i : c_set) c.push_back(i);

    sort(r.begin(), r.end());
    sort(c.begin(), c.end());

    for (int i : r) {
        sort(rows[i].begin(), rows[i].end());
    }
    for (int i : c) {
        sort(cols[i].begin(), cols[i].end());
    }

    for (int i : r) {
        res1 += rows[i][0];
        res1 += n - 1 - rows[i][rows[i].size() - 1];

        int start = rows[i][0];
        for (int end : rows[i]) {
            if (end == start) continue;
            res2 += end - start - 1;
            start = end;
        }
    }

    for (int i : c) {
        res1 += cols[i][0];
        res1 += m - 1 - cols[i][cols[i].size() - 1];

        int start = cols[i][0];
        for (int end : cols[i]) {
            if (end == start) continue;
            res2 += end - start - 1;
            start = end;
        }
    }

    for (int i : r) {
        for (int j : c) {
            int light = false;
            for (int k : cols[j]) {
                if (k == i) {
                    light = true;
                    break;
                }
            };
            if (light) continue;

            if ((j < rows[i][0] || j > rows[i][rows[i].size() - 1]) && (i < cols[j][0] || i > cols[j][cols[j].size() - 1])) {
                res11++;
            } else if ((j < rows[i][0] || j > rows[i][rows[i].size() - 1]) || (i < cols[j][0] || i > cols[j][cols[j].size() - 1])) {
                res21++;
            } else {
                res22++;
            }
        }
    }

    res1 -= (res21 + 2 * res11);
    res2 -= (res21 + 2 * res22);

    res0 = n * m - res1 - res2 - res11 - res21 - res22 - light_cnt;

    cout << res0 << " " << res1 << " " << res11 + res2 << " " << res21 << " " << res22 << endl;

    return 0;
}