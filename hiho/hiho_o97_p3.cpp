#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int N, M;
vector<vector<int>> vex;

int main() {
    cin >> N >> M;

    vex = vector<vector<int>>(N + 1, vector<int>{});

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        vex[u].push_back(v);
    }

    for (int i = 1; i <= N; i++) {
        vector<bool> vst(N + 1);
        vector<int> next;
        int res = 0;

        next.push_back(i);
        res++;
        vst[i] = 1;

        int r = 0, f = 0;
        while(r <= f) {
            int id = next[r];
            r++;

            for (int v : vex[id]) {
                if (vst[v]) continue;

                next.push_back(v);
                vst[v] = 1;
                res++;
                f++;
            }
        }

        cout << res << endl;
    }

    return 0;
}