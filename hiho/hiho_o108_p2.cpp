#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> parent(N + 1);
    for (int i = 1; i <= N; i++) cin >> parent[i];

    vector<int> query(Q);
    for (int i = 0; i < Q; i++) cin >> query[i];

    vector<vector<int>> children(N + 1);
    for (int i = 0; i <= N; i++) {
        children[parent[i]].push_back(i);
    }

    vector<int> que;
    vector<int> depth(N + 1);
    int f = 0;
    for (int i = 1; i <= N; i++) {
        if (children[i].empty()) {
            que.push_back(i);
            depth[i] = 2;
        }
    }

    vector<int> vst(N + 1, 0);
    int max_depth = 2;
    while (que.size() > f) {
        int cur = que[f];
        f++;

        if (vst[cur] == 1) continue;
        vst[cur] = 1;

        depth[cur] = depth[children[cur][0]] + 1;
        if (vst[parent[cur]] == 0) que.push_back(parent[cur]);

        max_depth = max(depth[cur], max_depth);
    }

    vector<int> count(max_depth + 1, 0);
    for (int i = 1; i <= N; i++) {
        count[depth[i]]++;
    }

    vector<int> remain(max_depth + 1, 0);
    remain[1] = N;
    for (int i = 2; i <= max_depth; i++) {
        remain[i] = remain[i - 1] - count[i];
    }

    for (int i = 0; i < Q; i++) {
        int M;
        cin >> M;

        auto p = upper_bound(remain.begin() + 1, remain.end(), M);
        if (p == remain.end()) {
            cout << remain.size() - 1 << endl;
        } else {
            int idx = p - remain.begin();

            if (idx == 1) {
                cout << 1 << endl;
            } else {
                int bf = remain[idx - 1];
                int af = remain[idx];

                int day = M - bf > af - M ? idx - 1 : idx;
                cout << day << endl;
            }
        }
    }

    return 0;
}

