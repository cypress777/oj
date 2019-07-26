#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    int m = max(a, b);
    int n = min(a, b);

    while (n > 0) {
        int tmp = n;
        n = m % n;
        m = tmp;
    }

    return m;
}

struct SegmentTree {
    SegmentTree(const vector<int> &array) {
        int n = array.size();
        tree = vector<int>(n * 6);

        Build(1, 0, n - 1, array);
    }

    void Build(int root, int start, int end, const vector<int> &arr) {
        if (start == end) {
            tree[root] = arr[start];
        } else {
            int mid = (start + end) / 2;
            Build(root * 2, start, mid, arr);
            Build(root * 2 + 1, mid + 1, end, arr);
            tree[root] = gcd(tree[root * 2], tree[root * 2 + 1]);
        }
    }

    int Query(int root, int start, int end, int qstart, int qend) {
        if (qstart > end || qend < start) return -1;

        if (start >= qstart && end <= qend) return tree[root];

        int mid = (start + end) / 2;
        int val1 = Query(root * 2, start, mid, qstart, qend);
        int val2 = Query(root * 2 + 1, mid + 1, end, qstart, qend);

        if (val1 == -1) return val2;
        if (val2 == -1) return val1;
        return gcd(val1, val2);
    }

    vector<int> tree;
};

int main() {
    int N;
    cin >> N;

    vector<int> tick(N);
    for (int i = 0; i < N; i++) {
        cin >> tick[i];
    }

    vector<int> period(N - 1);
    for (int i = 0; i < N - 1; i++) {
        period[i] = tick[i + 1] - tick[i];
    }

    auto seg_tree = SegmentTree(period);

    unordered_set<int> res;
    res.insert(seg_tree.Query(1, 0, N - 2, 0, N - 2));
    res.insert(seg_tree.Query(1, 0, N - 2, 1, N - 2));
    res.insert(seg_tree.Query(1, 0, N - 2, 0, N - 3));

    for (int i = 1; i < period.size(); i++) {
        int new_period = period[i] + period[i - 1];
        int val1, val2;
        if (i == 1) {
            val1 = new_period;
        } else {
            val1 = seg_tree.Query(1, 0, N - 2, 0, i - 2);
        }

        if (i == period.size() - 1) {
            val2 = new_period;
        } else {
            val2 = seg_tree.Query(1, 0, N - 2, i + 1, N - 2);
        }

//        cout << i << " " << new_period << " " << val1 << " " << val2 << endl;

        int val = gcd(val1, val2);
        val = gcd(val, new_period);

        res.insert(val);
    }

    vector<int> sorted(res.begin(), res.end());
    sort(sorted.begin(), sorted.end());
    for (int v : sorted) cout << v << endl;

    return 0;
}

