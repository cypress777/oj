#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

int len;

struct query {
    int id, l, r;
    query() {};
    query(int id_, int l_, int r_) : id(id_), l(l_), r(r_) {};
};

bool comp(query a, query b) {
    return (a.l / len == a.l / len ? a.l / len < b.l / len : a.r / len < b.r / len);
}

int lowbit(int n) {
    return n & ~(n - 1);
}

int get(const vector<int> &s, int n) {

}

int set(vector<int> &s, int n) {

}

void del(vector<int> &s, int n) {

}

void Solve() {
    int n, m, len;
    cin >> n >> m;
    len = (int)sqrt(n);
    vector<int> a(n, -1);
    vector<query> q(m, query());
    vector<int> s;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        q[i] = move(query(i, l, r));
    }

    sort(q.begin(), q.end(), comp);

    int pl = -1, pr = -1;
    for (int i = 0; i < q.size(); i++) {

    }
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) Solve();

    return 0;
}