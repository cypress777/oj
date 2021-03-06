#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int N, M, Q;

struct SegmentTree {
    SegmentTree(int n) {
        tree_ = vector<int>(6 * n);
        add_mark_ = vector<int>(6 * n);
    }

    SegmentTree(const vector<int> &arr) {
        int n = arr.size();
        tree_ = vector<int>(6 * n);
        add_mark_ = vector<int>(6 * n);
        Build(1, 0, n - 1, arr);
    }

    int Query(int root, int start, int end, int qstart, int qend) {
//        cout << "get max: " << root << " " << start << " " << end << " " << qstart << " " << qend << " " << tree_[root] << endl;
        if (qstart > end || qend < start) return -1;
        if (start >= qstart && end <= qend) return tree_[root];
        PushDown(root);
        int mid = (start + end) / 2;
        return max(Query(root * 2, start, mid, qstart, qend), Query(root * 2 + 1, mid + 1, end, qstart, qend));
    }

    void Build(int root, int start, int end, const vector<int> &arr) {
        add_mark_[root] = 0;
        if (start == end) {
            tree_[root] = arr[start];
        } else {
            int mid = (start + end) / 2;
            Build(root * 2, start, mid, arr);
            Build(root * 2 + 1, mid + 1, end, arr);
            tree_[root] = max(tree_[root * 2], tree_[root * 2 + 1]);
        }
    }

    void PushDown(int root) {
        if (add_mark_[root] != 0) {
            add_mark_[root * 2] += add_mark_[root];
            add_mark_[root * 2 + 1] += add_mark_[root];
            tree_[root * 2] += add_mark_[root];
            tree_[root * 2 + 1] += add_mark_[root];
            add_mark_[root] = 0;
        }
    }

    void UpdateOne(int root, int start, int end, int id, int val) {
        if (start == end) {
            if (id == start) tree_[root] += val;
            return;
        }
        int mid = (start + end) / 2;
        if (id <= mid) UpdateOne(root * 2, start, mid, id, val);
        else UpdateOne(root * 2 + 1, mid + 1, end, id, val);
        tree_[root] = max(tree_[root * 2], tree_[root * 2 + 1]);
    }

    void Update(int root, int start, int end, int ustart, int uend, int val) {
        if (ustart > end || uend < start) return;
        if (ustart <= start && uend >= end) {
            add_mark_[root] += val;
            tree_[root] += val;
            return;
        }
        PushDown(root);
        int mid = (start + end) / 2;
        Update(root * 2, start, mid, ustart, uend, val);
        Update(root * 2 + 1, mid + 1, end, ustart, uend, val);
        tree_[root] = max(tree_[root * 2], tree_[root * 2 + 1]);
    }

    vector<int> tree_;
    vector<int> add_mark_;
};

vector<vector<int>> map;
vector<vector<int>> up_sum;
vector<vector<int>> down_sum;
vector<vector<int>> right_sum;
vector<vector<int>> left_sum;
vector<vector<int>> left_sum_T;
vector<SegmentTree> horizontal_tree;
vector<SegmentTree> vertical_tree;

int main() {
    cin >> N >> M >> Q;

    map = vector<vector<int>>(N, vector<int>(M));
    up_sum = vector<vector<int>>(N, vector<int>(M));
    down_sum = vector<vector<int>>(N, vector<int>(M));
    right_sum = vector<vector<int>>(N, vector<int>(M));
    left_sum = vector<vector<int>>(N, vector<int>(M));
    left_sum_T = vector<vector<int>>(M, vector<int>(N));
    horizontal_tree = vector<SegmentTree>(N, SegmentTree(M));
    vertical_tree = vector<SegmentTree>(M, SegmentTree(N));

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) map[i][j] = s[j] - '0';
    }

    for (int i = 0; i < M; i++)
        for (int j = 1; j < N; j++)
            if (map[j][i] == map[j - 1][i])
                up_sum[j][i] = up_sum[j - 1][i] + 1;
    for (int i = 0; i < N; i++)
        for (int j = 1; j < M; j++)
            if (map[i][j] == map[i][j - 1]) {
                left_sum[i][j] = left_sum[i][j - 1] + 1;
                left_sum_T[j][i] = left_sum[i][j];
            }
    for (int i = 0; i < M; i++)
        for (int j = N - 2; j >= 0; j--)
            if (map[j][i] == map[j + 1][i])
                down_sum[j][i] += down_sum[j + 1][i] + 1;
    for (int i = 0; i < N; i++)
        for (int j = M - 2; j >= 0; j--)
            if (map[i][j] == map[i][j + 1])
                right_sum[i][j] += right_sum[i][j + 1] + 1;

//    for (int i = 0; i < N; i++) horizontal_tree.emplace_back(SegmentTree(M, up_sum[i]));
//    for (int i = 0; i < M; i++) vertical_tree.emplace_back(SegmentTree(N, left_sum_T[i]));

    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) horizontal_tree[i].UpdateOne(1, 0, M - 1, j, up_sum[i][j]);
    for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) vertical_tree[i].UpdateOne(1, 0, N - 1, j, left_sum[j][i]);

    for (int i = 0; i < Q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        if (map[r1][c1] != map[r2][c2]) {
            cout << -1 << endl;
            continue;
        }

        int w = abs(c2 - c1);
        int h = abs(r2 - r1);

        if (r1 == r2 && left_sum[r2][max(c1, c2)] >= w - 1 || c1 == c2 && up_sum[max(r1, r2)][c2] >= h - 1) {
            cout << 0 << endl;
            continue;
        }

        if (r1 != r2 && c1 != c2) {
            if (c2 > c1 && r2 > r1 &&
                (map[r1][c2] == map[r1][c1] && left_sum[r1][c2] >= w - 1 && down_sum[r1][c2] >= h - 1 ||
                 map[r2][c1] == map[r1][c1] && right_sum[r2][c1] >= w - 1 && up_sum[r2][c1] >= h - 1) ||
                c2 > c1 && r1 > r2 &&
                (map[r2][c1] == map[r1][c1] && right_sum[r2][c1] >= w - 1 && down_sum[r2][c1] >= h - 1 ||
                 map[r1][c2] == map[r1][c1] && left_sum[r1][c2] >= w - 1 && up_sum[r1][c2] >= h - 1) ||
                c1 > c2 && r2 > r1 &&
                (map[r1][c2] == map[r1][c1] && right_sum[r1][c2] >= w - 1 && down_sum[r1][c2] >= h - 1 ||
                 map[r2][c1] == map[r1][c1] && left_sum[r2][c1] >= w - 1 && up_sum[r2][c1] >= h - 1) ||
                c1 > c2 && r1 > r2 &&
                (map[r2][c1] == map[r1][c1] && left_sum[r2][c1] >= w - 1 && down_sum[r2][c1] >= h - 1 ||
                 map[r1][c2] == map[r1][c1] && right_sum[r1][c2] >= w - 1 && up_sum[r1][c2] >= h - 1)) {
                cout << 1 << endl;
                continue;
            }
        }

        int c_max = min(right_sum[r1][c1] + c1, right_sum[r2][c2] + c2);
        int c_min = max(c1 - left_sum[r1][c1], c2 - left_sum[r2][c2]);
        int r_max = min(down_sum[r1][c1] + r1, down_sum[r2][c2] + r2);
        int r_min = max(r1 - up_sum[r1][c1], r2 - up_sum[r2][c2]);
        if (c_max >= c_min && horizontal_tree[max(r1, r2)].Query(1, 0, M - 1, c_min, c_max) >= abs(r2 - r1) - 1 ||
            r_max >= r_min && vertical_tree[max(c1, c2)].Query(1, 0, N - 1, r_min, r_max) >= abs(c2 - c1) - 1) {
            cout << 2 << endl;
            continue;
        }
        cout << -1 << endl;
    }

    return 0;
}