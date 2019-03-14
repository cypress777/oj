#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> bst;
vector<int> f;
queue<vector<int>> que;


int main() {
    cin >> N;

    bst = vector<int>(N, 0);
    for (int i = 0; i < N; i++) cin >> bst[i];

    f.emplace_back(0);
    que.push(bst);
    while (!que.empty()) {
        vector<int> v = que.front();
        que.pop();

        int fv  = v[0];

        vector<int> L, R;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] < fv) L.emplace_back(v[i]);
            if (v[i] > fv) R.emplace_back(v[i]);
        }
        if (!L.empty()) {
            f.emplace_back(fv);
            que.push(L);
        }
        if (!R.empty()) {
            f.emplace_back(fv);
            que.push(R);
        }
    }

    for (int i = 0; i < f.size(); i++) {
        if (i != f.size() - 1) cout << f[i] << " ";
        else cout << f[i] << endl;
    }

    return 0;
}