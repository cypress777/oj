#include <vector>
#include <iostream>

using namespace std;

int N, M;
vector<vector<int>> edges;
vector<int> result;
vector<int> deg;
vector<int> flg;

int main() {
    cin >> N >> M;

    edges = vector<vector<int>>(N + 1, vector<int>());
    result = vector<int>(N + 1, 0);
    deg = vector<int>(N + 1, 0);
    flg = vector<int>(N + 1, -1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edges[b].push_back(a);
        deg[b]++;
    }

    vector<int> que(1, 1);
    flg[1] = 1;
    result[1] = 0;
    int r = 0, f = 0;
    while (r <= f) {
        int p = que[r];
        for (int i = 1; i <= N; i++) {
            if (flg[i] != -1) continue;
            for (int j = 0; j < edges[i].size(); j++) {
                if (edges[i][j] == p) {
                    deg[i]--;
                    break;
                }
            }
            if (deg[i] == 0) {
                result[i] = p;
                que.push_back(i);
                flg[i] = 1;
                f++;
            }
        }
        r++;
    }

    for (int i = 1; i <= N; i++) cout << result[i] << endl;
}