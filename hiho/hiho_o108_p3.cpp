#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int INF = 1000000002;

void swap(int &u, int &v) {
    int tmp = u;
    u = v;
    v = tmp;
}

int log_2(int val) {
   return floor(log(val) / log(2));
}

void get_depth(const vector<vector<int>> &child, int root, vector<int> &depth) {
    for (int i = 0; i < child[root].size(); i++) {
        depth[child[root][i]] = depth[root] + 1;
        get_depth(child, child[root][i], depth);
    }
}

int get_ancesetor(int node, int steps, const vector<vector<int>> &fa) {
    while (steps > 0) {
        int k = log_2(steps);
        node = fa[node][k];
        steps = steps - pow(2, k);
    }
    return node;
}

int get_weight(int node, int steps, const vector<vector<int>> &fa, const vector<vector<int>> &weight) {
    int w = weight[node][0];
    while (steps > 0) {
        int k = log_2(steps);
        w = min(w, weight[node][k]);
        node = fa[node][k];
        steps = steps - pow(2, k);
    }
    return w;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    int MM = ceil(log(N) / log(2));

    vector<vector<int>> child(N + 1);
    vector<vector<int>> fa(N + 1, vector<int>(MM + 1, 0));
    vector<vector<int>> weight(N + 1, vector<int>(MM + 1, INF));
    int root = 0;

    for (int i = 1; i <= N; i++) {
        cin >> fa[i][0] >> weight[i][0];
        if (fa[i][0] == 0) weight[i][0] = INF;
        child[fa[i][0]].push_back(i);
    }

    vector<int> depth(N + 1, -1);
    get_depth(child, 0, depth);

//    cout << "depth:" << endl;
//    for (int i = 0; i <= N; i++) {
//        cout << depth[i] << " ";
//    }
//    cout << endl << "----" << endl;

    for (int i = 1; i <= MM; i++) {
        for (int j = 1; j <= N; j++) {
            if (fa[j][i - 1] <= 0) continue;

            fa[j][i] = fa[fa[j][i - 1]][i - 1];
            weight[j][i] = min(weight[fa[j][i - 1]][i - 1], weight[j][i - 1]);
        }
    }

//    for (int i = 0; i <= MM; i++) {
//        cout << "---- " << i << endl;
//        for (int j = 1; j <= N; j++) {
//            cout << j << " " << fa[j][i] << " " << weight[j][i] << endl;
//        }
//    }

    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;

        if (depth[u] > depth[v]) swap(u, v);
        int ori_u = u, ori_v = v;

        int diff = depth[v] - depth[u];
        v = get_ancesetor(v, diff, fa);

        int left = 0;
        int right = depth[u];
        int mid = floor((left + right) / 2);

        while (left <= right) {
            u = get_ancesetor(u, mid, fa);
            v = get_ancesetor(v, mid, fa);

            if (u != v) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }

            mid = floor((left + right) / 2);
        }

        int u_steps = depth[ori_u] - depth[u];
        int v_steps = depth[ori_v] - depth[v];

        int uw = get_weight(ori_u, u_steps, fa, weight);
        int vw = get_weight(ori_v, v_steps, fa, weight);

        cout << min(uw, vw) << endl;
    }

    return 0;
}

