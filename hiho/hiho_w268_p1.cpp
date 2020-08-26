#include <iostream>
#include <vector>

using namespace std;

struct QuickUnion {
    vector<int> root, sz;
    vector<int> diff;

    explicit QuickUnion(int N) {
        root = vector<int>(N + 1);
        sz = vector<int>(N + 1, 1);
        diff = vector<int>(N + 1, 0);

        for (int i = 1; i <= N; i++) root[i] = i;
    }

    void insert(int x, int y, int s) {
        int rx = get_root(x);
        int ry = get_root(y);

        if (rx == ry) return;

        if (sz[rx] > sz[ry]) {
            root[ry] = rx;
            sz[rx] += sz[ry];
            diff[ry] = (diff[x] - s) - diff[y];
        } else {
            root[rx] = ry;
            sz[ry] = rx;
            diff[rx] = (s + diff[y]) - diff[x];
        }
    }

    int get_root(int id) {
        if (root[id] == id) return id;

        int r = get_root(root[id]);
        diff[id] += diff[root[id]];
        root[id] = r;

        return r;
    }

    int get_diff(int id) {
        get_root(id);

        return diff[id];
    }

    int compare(int x, int y) {
        int rx = get_root(x);
        int ry = get_root(y);

        if (rx != ry) return -1;

        return get_diff(x) - get_diff(y);
    }
};

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    auto quick_union = QuickUnion(N);

    for (int i = 0; i < M; i++) {
        int x, y, s;
        cin >> x >> y >> s;

        quick_union.insert(x, y, s);
    }

    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;

        cout << quick_union.compare(x, y) << endl;
    }

    return 0;
}
