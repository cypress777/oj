#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int a;
    int b;
    int v;
};

bool comp(const struct edge &a, const struct edge &b) {
    return a.v < b.v;
}

int n, m;
int MM = 1000;
vector<struct edge> edges;
vector<int> f;
vector<int> s;

int get_f(int v) {
    if (f[v] == -1) return v;
    f[v] = get_f(f[v]);
    return f[v];
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        struct edge e;
        cin >> e.a;
        cin >> e.b;
        e.a--;
        e.b--;
        cin >> e.v;
        edges.push_back(e);
    }

    sort(edges.begin(), edges.end(), comp);

    f = vector<int>(n, -1);
    s = vector<int>(n,  1);

    int spent = 0;
    for (int i = 0; i < m; i++) {
        int fa = get_f(edges[i].a);
        int fb = get_f(edges[i].b);
        if (fa != fb) {
            if (s[fa] > s[fb]) {
                f[fb] = fa;
                s[fa] += s[fb];
            } else {
                f[fa] = fb;
                s[fb] += s[fa];
            }
            spent += edges[i].v;
        } else {
            continue;
        }
    }

    cout << spent << endl;
    return 0;
}