#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

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
        node = fa[node][k];
        w = min(w, weight[node][k]);
        steps = steps - pow(2, k);
    }
    return w;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    int MM = ceil(log(N) / log(2));

    vector<vector<int>> child(N + 1);
    vector<vector<int>> fa(N + 1, vector<int>(MM + 1, -1));
    vector<vector<int>> weight(N + 1, vector<int>(MM + 1, -1));
    int root = 0;

    for (int i = 1; i <= N; i++) {
        cin >> fa[i][0] >> weight[i][0];
        child[fa[i][0]].push_back(i);
    }

    vector<int> depth(N + 1, 0);
    get_depth(child, 0, depth);

    for (int i = 1; pow(2, i) <= MM; i++) {
        for (int j = 1; j <= N; j++) {
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
            weight[j][i] = min(weight[fa[j][i - 1]][i - 1], weight[j][i - 1]);
        }
    }

    vector<int> u(Q), v(Q);
    for (int i = 0; i < Q; i++) cin >> u[i] >> v[i];

    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        if (depth[u] > depth[v]) swap(u, v);

        int diff = depth[v] - depth[u];

        int left = 0;
        int right = depth[u];
        int mid = floor((left + right) / 2);

        while (left < right) {
            int fu = get_ancesetor(u, mid, fa);
            int fv = get_ancesetor(v, diff + mid, fa);

            if (fu != fv) {
                left = mid;
            } else {
                right = mid;
            }

            u = fu;
            v = fv;
            mid = floor((left + right) / 2);
        }

        int steps = left;
        cout << steps << endl;

        int uw = get_weight(u, steps, fa, weight);
        int vw = get_weight(v, steps + diff, fa, weight);

        cout << min(uw, vw) << endl;
    }

    return 0;
}

