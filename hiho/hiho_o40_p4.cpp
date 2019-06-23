#include <iostream>
#include <vector>

using namespace std;

int MM = 100001;

struct SegTree {
    SegTree() {
        h = vector<int>(MM, 0);
        tree = vector<int>(MM * 8, 0);
        flg = vector<int>(MM * 8, 0);
    }

    void push_up(int rt) {
        tree[rt] = max(tree[rt * 2], tree[rt * 2 + 1]);
    }

    void push_down(int rt) {
        if (flg[rt] > 0) {
            flg[rt * 2] = max(flg[rt], flg[rt * 2]);
            flg[rt * 2 + 1] = max(flg[rt], flg[rt * 2 + 1]);
            tree[rt * 2] = max(flg[rt * 2], tree[rt * 2]);
            tree[rt * 2 + 1] = max(flg[rt * 2 + 1], tree[rt * 2 + 1]);
            flg[rt] = 0;
        }
    }

    void build(int rt, int l, int r) {
        if (l == r) {
            tree[rt] = h[l];
        } else {
            build(rt * 2, l, (l + r) / 2);
            build(rt * 2 + 1, (l + r) / 2 + 1, r);
        }

        push_up(rt);
    };

    void update(int rt, int l, int r, int ul, int ur, int v) {
        if (l >= ul && r <= ur) {
            tree[rt] = max(v, tree[rt]);
            flg[rt] = max(v, flg[rt]);
            return;
        }

        push_down(rt);

        if ((l + r) / 2 >= ul) update(rt * 2, l, (l + r) / 2, ul, ur, v);
        if ((l + r) / 2 + 1 <= ur) update(rt * 2 + 1, (l + r) / 2 + 1, r, ul, ur, v);

        push_up(rt);
    }

    int query(int rt, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return -1;
        if (l >= ql && r <= qr) return tree[rt];

        push_down(rt);

        int p1, p2;
        p1 = query(rt * 2, l, (l + r) / 2, ql, qr);
        p2 = query(rt * 2 + 1, (l + r) / 2 + 1, r, ql, qr);

        return max(p1, p2);
    }

    vector<int> h;
    vector<int> tree;
    vector<int> flg;
};

int main() {
    int N;
    cin >> N;

    SegTree seg_tree;
    seg_tree.build(1, 1, MM - 1);

    vector<int> l(N);
    vector<int> r(N);
    for (int i = 0; i < N; i++) {
        cin >> l[i] >> r[i];
        int h = seg_tree.query(1, 1, MM - 1, l[i], r[i]);
        cout << h + 1 << endl;
        seg_tree.update(1, 1, MM - 1, l[i], r[i], h + 1);
    }

    return 0;
}

