#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

int len;
int MM = 20010;

struct Query {
    int id, l, r;
    Query() {};
    Query(int id_, int l_, int r_) : id(id_), l(l_), r(r_) {};
};

bool comp(const Query &a, const Query &b) {
    if (a.l / len != b.l / len) return a.l / len < b.l / len;
    return a.r / len < b.r / len;
}

int lowbit(int n) {
    return n & ~(n - 1);
}

template <typename T>
T get(const vector<T> &vec, int num) {
    T res = 0;
    for (; num > 0; res += vec[num], num -= lowbit(num));
    return res;
}

template <typename T>
void set(vector<T> &vec, int num, T val) {
    for (; num < vec.size(); vec[num] += val, num += lowbit(num));
}

void Solve() {
    int n, m;
    cin >> n >> m;
    len = (int)sqrt(n);

    vector<long long> waits(n + 1, 0);
    vector<Query> queries(m, Query());
    vector<long long> results(m, 0);
    vector<long long> sums(MM + 1, 0);
    vector<int> index(MM + 1, 0);

    for (int i = 1; i <= n; i++) cin >> waits[i];
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = Query(i, l, r);
    }

    sort(queries.begin(), queries.end(), comp);

    int pl = 1, pr = 0;
    long long res = 0;
    for (int i = 0; i < queries.size(); i++) {
        while (queries[i].r > pr) {
            pr++;
            set(sums, waits[pr], waits[pr]);
            set(index, waits[pr], 1);
            int k = get(index, waits[pr]);
            long long s = get(sums, waits[pr]);
            res += s + waits[pr] * (pr - pl + 1 - k);
        }
        while (queries[i].l < pl) {
            pl--;
            set(sums, waits[pl], waits[pl]);
            set(index, waits[pl], 1);
            int k = get(index, waits[pl]);
            long long s = get(sums, waits[pl]);
            res += s + waits[pl] * (pr - pl + 1 - k);
        }
        while (queries[i].r < pr) {
            int k = get(index, waits[pr]);
            long long s = get(sums, waits[pr]);
            res -= s + waits[pr] * (pr - pl + 1 - k);
            set(sums, waits[pr], -waits[pr]);
            set(index, waits[pr], -1);
            pr--;
        }
        while (queries[i].l > pl) {
            int k = get(index, waits[pl]);
            long long s = get(sums, waits[pl]);
            res -= s + waits[pl] * (pr - pl + 1 - k);
            set(sums, waits[pl], -waits[pl]);
            set(index, waits[pl], -1);
            pl++;
        }
        results[queries[i].id] = res;
    }

    for (long long res : results) cout << res << endl;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) Solve();

    return 0;
}