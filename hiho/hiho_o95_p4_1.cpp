#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, maxn;
vector<int> bst;
vector<int> sorted_bst;
vector<int> res;
queue<vector<int>> que;


int main() {
    cin >> N;

    bst = vector<int>(N, 0);
    maxn = 0;
    for (int i = 0; i < N; i++) {
        cin >> bst[i];
        if (bst[i] > maxn) maxn = bst[i];
    }
    sorted_bst = bst;
    sort(sorted_bst.begin(), sorted_bst.end());

    res.emplace_back(0);
    que.push({0, 0, N - 1});

    int p = 1;
    while (!que.empty()) {
        vector<int> v = que.front();
        que.pop();

        int fid = v[0];
        int fv = bst[v[0]];

        int sorted_fid = lower_bound(sorted_bst.begin() + v[1], sorted_bst.begin() + v[2] + 1, fv) - sorted_bst.begin(); // !!!!!!!!

        if (sorted_fid > v[1]) {
            res.emplace_back(fv);
            que.push({p, v[1], sorted_fid - 1});
            p++;
        }
        if (sorted_fid < v[2]) {
            res.emplace_back(fv);
            que.push({p, sorted_fid + 1, v[2]});
            p++;
        }
    }

    for (int i = 0; i < res.size(); i++) {
        if (i != res.size() - 1) cout << res[i] << " ";
        else cout << res[i] << endl;
    }

    return 0;
}