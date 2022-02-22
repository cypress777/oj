#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int to, res, rev;
    Edge() {}
    Edge(int t, int r, int rv) : to(t), res(r), rev(rv) {}
};

struct Graph {
    int n, m, k, s, t;
    vector<vector<Edge>> rGraph;

    Graph() {
        // int tmp;
        // cin >> n >> m;
        scanf("%d%d", &n, &m);
        k = n + 2;
        s = n;
        t = n + 1;

        rGraph = vector<vector<Edge>>(k, vector<Edge>{});

        int x, y;
        // while (scanf("%d%d", &x, &y) > 0) {
            // cout << x << ' ' << y << endl;
        while (cin >> x >> y) {
            addEdge(x - 1, y - 1);
        }

        for (int i = 0; i < m; i++) addEdge(s, i);

        for (int i = m; i < n; i++) addEdge(i, t);
    }

    void addEdge(int x, int y) {
        auto fromEdge = Edge(y, 1, rGraph[y].size());
        auto toEdge = Edge(x, 0, rGraph[x].size());

        rGraph[x].push_back(fromEdge);
        rGraph[y].push_back(toEdge);
    }

    bool dfs(vector<int>& path, int curr) {
        // cout << "-- " << curr << endl;
        if (curr == t) return true;

        for (int i = 0; i < rGraph[curr].size(); i++) {
            if (path[rGraph[curr][i].to] != -1) continue;
            if (rGraph[curr][i].res <= 0) continue;

            path[curr] = i;
            bool found = dfs(path, rGraph[curr][i].to);

            if (found) return true;
            else path[curr] = -1;
        }
        
        return false;
    }

    int EK() {
        int tot_flow = 0;

        vector<int> path(k, -1);
        while (dfs(path, s)) {
            // cout << "++++ " << endl;
            int path_flow = INT_MAX;

            for (int x = s; x != t; x = rGraph[x][path[x]].to) {
                // cout << x << " " << path[x] << " " << rGraph[x][path[x]].to << endl;
                path_flow = min(path_flow, rGraph[x][path[x]].res);
            }

            for (int x = s; x != t; x = rGraph[x][path[x]].to) {
                rGraph[x][path[x]].res -= path_flow;

                auto edge = rGraph[x][path[x]];
                rGraph[edge.to][edge.rev].res += path_flow;
            }

            tot_flow += path_flow;

            for (int i = 0; i < k; i++)  path[i] = -1;
        }

        cout << tot_flow << endl;
        return tot_flow;
    }
};

int main() {
    // freopen("in.txt", "r", stdin);

    auto graph = Graph();
    return graph.EK();

    return 0;
}