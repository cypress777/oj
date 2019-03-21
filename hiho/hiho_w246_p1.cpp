#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

int len;

struct query {
    int l, r;
    query() {};
    query(int l_, int r_) : l(l_), r(r_) {};
};

bool comp(query a, query b) {
    return (a.l / len == a.l / len ? a.l / len < b.l / len : a.r / len < b.r / len);
}

void Solve() {
    int n, m, len;
    cin >> n >> m;
    len = (int)sqrt(n);
    vector<int> a(n, -1);
    vector<query> q(m, query());

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        q[i] = move(query(l, r));
    }


}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) Solve();

    return 0;
}