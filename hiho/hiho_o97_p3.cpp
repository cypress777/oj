#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int N, M;
vector<vector<int>> vex;
vector<unordered_set<int>> res;
vector<int> flg;

int main() {
    cin >> N >> M;

    vex = vector<vector<int>>(N + 1, vector<int>{});
    for (int i = 1; i <= N; i++) vex[i].push_back(i);
    res = vector<unordered_set<int>>(N + 1, unordered_set<int>{});
    flg = vector<int>(N + 1, -1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        vex[u].push_back(v);
    }

    for (int i = 1; i <= N; i++) {
        vector<int> vst(N + 1, -1);
        queue<int> next{};

        for (int j = 0; j < vex[i].size(); j++) next.push(vex[i][j]);

        while(!next.empty()) {
            int id = next.front();
            next.pop();
            if (vst[id] != -1) continue;
            vst[id] = 1;
            res[i].insert(id);
            if (flg[id] != -1) {
                for (auto v : res[id]) res[i].insert(v);
                continue;
            } else {
                for (int j = 0; j < vex[id].size(); j++) next.push(vex[id][j]);
            }
        }
        flg[i] = 1;
    }

    for (int i = 1; i <= N; i++) {
        cout << res[i].size() << endl;
    }

    return 0;
}