#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> edges;
vector<int> edge_s;
vector<int> edge_e;
vector<int> dist;

int inf = 10000;
int N, M;

vector<int> find_paths(int ori) {
    vector<int> paths = edges[ori];

    vector<int> flg(N + 1, 0);
    flg[ori] = 1;

    int cnt = 1;

    while (cnt <= N) {
        int min_id = 0, min_val = inf;
        for (int i = 1; i <= N; i++) {
            if (flg[i] == 1) continue;

            if (paths[i] < min_val) {
                min_val = paths[i];
                min_id = i;
            }

            flg[min_id] = 1;
            cnt++;
            if (min_val >= inf) break;

            for (int i = 1; i <= N; i++) {
                if (paths[i] > paths[min_id] + edges[min_id][i]) paths[i] = paths[min_id] + edges[min_id][i];
            }
        }
    }

    return paths;
}

int main() {
    cin >> N >> M;

    edges = vector<vector<int>>(N + 1, vector<int>(N + 1, inf));

    edge_s = vector<int>(M);
    edge_e = vector<int>(M);
    dist = vector<int>(M, inf);

    for (int i = 0; i < M; i++) {
        cin >> edge_s[i];
        cin >> edge_e[i];
        cin >> dist[i];

        edges[edge_s[i]][edge_s[i]] = 0;
        edges[edge_e[i]][edge_e[i]] = 0;
        edges[edge_s[i]][edge_e[i]] = min(dist[i], edges[edge_s[i]][edge_e[i]]);
        edges[edge_e[i]][edge_s[i]] = edges[edge_s[i]][edge_e[i]];
    }

    vector<int> path21 = find_paths(1);
    vector<int> path2N = find_paths(N);

    int min_12N = path21[N];

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        if (path21[edge_s[i]] + dist[i] + path2N[edge_e[i]] == path21[N] ||
            path21[edge_e[i]] + dist[i] + path2N[edge_s[i]] == path21[N]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

