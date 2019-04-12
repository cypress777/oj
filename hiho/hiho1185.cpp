#include <vector>
#include <iostream>

using namespace std;

int N, M;
vector<int> W;
vector<vector<int>> G;
vector<vector<int>> G_r;
vector<long long> W_n;
vector<vector<int>> G_n;
vector<int> flg;
vector<int> post_order;

void dfs_get_post(int start) {
    for (int id : G[start]) {
        if (flg[id] == -1) {
            flg[id] = 1;
            dfs_get_post(id);
        }
    }
    post_order.push_back(start);
}

void reverse_graph() {
    for (int i = 1; i <= N; i++) {
        for (int p : G[i]) {
            G_r[p].push_back(i);
        }
    }
}

long long dfs_by_order(int start) {
    long long val = W[start];

    for (int id : G_r[start]) {
        if (flg[id] == -1) {
            flg[id] = 1;
            val += W[id];
            dfs_by_order(id);
        }
    }

    return val;
}

long long dfs_get_max(int start) {
    long long val = W_n[start];

    long long increase = 0;
    for (int id : G_n[start]) {
        if (flg[id] == -1) {
            flg[id] = 1;
            long long tmp = dfs_get_max(id);
            if (tmp > increase) increase = tmp;
        }
    }

    return val += increase;
}

int main() {
    cin >> N >> M;
    W = vector<int>(N + 1, 0);
    G = vector<vector<int>>(N + 1, vector<int>());

    for (int i = 0; i < N; i++) cin >> W[i];
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        G[v].push_back(u);
    }

    flg = vector<int>(N + 1, -1);
    for (int i = 1; i <= N; i++) {
        if (flg[i] == -1) {
            flg[i] = 1;
            dfs_get_post(i);
        }
    }

    reverse_graph();

    G_n = G;
    W_n = vector<long long>(N + 1);
    flg = vector<int>(N + 1, -1);
    for (int id : post_order) {
        if (flg[id] == -1) {
            flg[id] = 1;
            W_n[id] = dfs_by_order(id);
            G_n[id] = vector<int>();
        }
    }

    flg = vector<int>(N + 1, -1);
    long long res = dfs_get_max(1);

    cout << res << endl;

    return 0;
}