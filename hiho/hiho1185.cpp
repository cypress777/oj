#include <vector>
#include <iostream>

using namespace std;

int N, M;
vector<int> W;
vector<vector<int>> G;
vector<vector<int>> G_r;
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

bool not_cc(int p, int q) {
    bool p2q = false, q2p = false;
    for (int id : G[p]) {
        if (id == q) {
            p2q = true;
            break;
        }
    }

    for (int id : G[q]) {
        if (id == p) {
            q2p = true;
            break;
        }
    }

    if (p2q && q2p) return false;
    else return true;
}

long long dfs_get_max(int start) {
    long long val = W[start];

    long long increase = 0;
    for (int id : G[start]) {
        if (flg[id] == -1) {
            flg[id] = 1;
            if (not_cc(id, start)) {
                long long tmp = dfs_get_max(id);
                if (tmp > increase) increase = tmp;
            }
        }
    }

    return val += increase;
}

int main() {
    cin >> N >> M;
    W = vector<int>(N + 1, 0);
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
//    for (int p : post_order) cout << p << " ";
//    cout << endl;
//    cout << "--------" << endl;

    reverse_graph();
//    for (int i = 1; i <= N; i++) {
//        for (int p : G[i]) cout << p << " ";
//        cout << endl;
//    }
//    cout << "--------" << endl;
//
//    for (int i = 1; i <= N; i++) {
//        for (int p : G_r[i]) cout << p << " ";
//        cout << endl;
//    }

    flg = vector<int>(N + 1, -1);
    for (int i = 0; i < post_order.size(); i++) {
        int id = post_order[post_order.size() - 1 - i];
        if (flg[id] == -1) {
            flg[id] = 1;
            vector<int> cc;
            long long cc_val = dfs_by_order(id, cc);
            for (int cc_id : cc) {
                cout << cc_id << " ";
                W[cc_id] = cc_val;
            }
            cout << endl;
        }
    }

    flg = vector<int>(N + 1, -1);
    flg[1] = 1;
    long long res = dfs_get_max(1);

    cout << res << endl;

    return 0;
}