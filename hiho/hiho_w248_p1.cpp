#include <vector>
#include <iostream>

using namespace std;

int N, M, K;
vector<int> layer_size;
vector<vector<int>> nodes;
vector<int> leaves;
vector<vector<int>> leaves_dist;
vector<int> child;
vector<int> parent;

int get_dist(int m, int n) {
    int d2m = 0, d2n = 0;
    while (child[m] != -1) {
        m = child[m];
        d2m++;
    }
    while (child[n] != -1) {
        n = child[n];
        d2n++;
    }

    int im, in;
    for (int i = 0; i < leaves.size(); i++) {
        if (m == leaves[i]) im = i;
        if (n == leaves[i]) in = i;
    }

    return leaves_dist[im][in] - d2m - d2n;
}

int get_next_p(int layer, int cur_p) {
    for (int i = cur_p + 1; i < nodes[layer].size(); i++) {
        bool avail = true;
        for (int l : leaves) {
            if (l == nodes[layer][i]) {
                avail = false;
                break;
            }
        }
        if (avail) return i;
    }
    return -1;
}

int main() {
    cin >> N >> M >> K;

    layer_size = vector<int>(M);
    nodes = vector<vector<int>>(M, vector<int>());
    child = vector<int>(N + 1, -1);
    leaves = vector<int>(K);
    leaves_dist = vector<vector<int>>(K, vector<int>(K));
    parent = vector<int>(N + 1);

    for (int i = 0; i < M; i++) cin >> layer_size[i];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < layer_size[i]; j++) {
            int n;
            cin >> n;
            nodes[i].push_back(n);
        }
    }

    for (int i = 0; i < K; i++) cin >> leaves[i];

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            cin >> leaves_dist[i][j];
        }
    }

    for (int i = M - 1; i > 0; i--) {
        int cur_p = -1;
        for (int j = 0; j < nodes[i].size(); j++) {
            if (j == 0 || get_dist(nodes[i][j], nodes[i][j - 1]) != 2) {
                cur_p = get_next_p(i - 1, cur_p);
                parent[nodes[i][j]] = nodes[i - 1][cur_p];
                child[nodes[i - 1][cur_p]] = nodes[i][j];
//                cout << "11111 " << i << " " << j << " " << nodes[i][j] << " " << cur_p << endl;
            } else {
                parent[nodes[i][j]] = nodes[i - 1][cur_p];
//                cout << "22222 " << i << " " << j << " " << nodes[i][j] << " " << cur_p << endl;
            }
        }
    }
    parent[nodes[0][0]] = 0;

    for (int i = 1; i <= N; i++) {
        if (i != N) cout << parent[i] << " ";
        else cout << parent[i] << endl;
    }

    return 0;
}