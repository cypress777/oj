#include <vector>
#include <iostream>

using namespace std;

int N, M;
vector<long long> W;
vector<vector<int>> G;
vector<vector<int>> G_r;
vector<vector<int>> CC;
vector<int> CC_id;
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

long long dfs_by_order(int start, vector<int> &grp) {
    long long val = W[start];
    grp.push_back(start);

    for (int id : G_r[start]) {
        if (flg[id] == -1) {
            flg[id] = 1;
            val += W[id];
            dfs_by_order(id, grp);
        }
    }

    return val;
}

long long dfs_get_max(int start) {
    long long val = W[start];
    for (int id : CC[CC_id[start]]) {
        flg[id] = 1;
    }

    long long increase = 0;
    for (int id : G[start]) {
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
    W = vector<long long>(N + 1, 0);
    CC_id = vector<int>(N + 1, -1);
    G = vector<vector<int>>(N + 1, vector<int>());
    G_r = vector<vector<int>>(N + 1, vector<int>());

    for (int i = 1; i <= N; i++) cin >> W[i];
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    flg = vector<int>(N + 1, -1);
    for (int i = 1; i <= N; i++) {
        if (flg[i] == -1) {
            flg[i] = 1;
            dfs_get_post(i);
        }
    }

    reverse_graph();

    flg = vector<int>(N + 1, -1);
    for (int i = 0; i < post_order.size(); i++) {
        int id = post_order[post_order.size() - 1 - i];
        if (flg[id] == -1) {
            flg[id] = 1;
            vector<int> cc;
            long long cc_val = dfs_by_order(id, cc);
            CC.push_back(cc);
            for (int cci : cc) {
                W[cci] = cc_val;
                CC_id[cci] = (CC.size() - 1);
            }
        }
    }

    flg = vector<int>(N + 1, -1);
    flg[1] = 1;
    long long res = dfs_get_max(1);

    cout << res << endl;

    return 0;
}
