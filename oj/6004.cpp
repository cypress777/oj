#include <bits/stdc++.h>

using namespace std;

// https://loj.ac/p/6004

struct Edge {
    int to, res, rev;
    Edge(int t, int rs, int rv) : to(t), res(rs), rev(rv) {}
};

struct RGraph {
    vector<vector<Edge>> rgraph;
    int m, n, s, t, k, tot;
    vector<vector<int>> seat;

    RGraph() {
        cin >> m >> n;
        s = m + n;
        t = m + n + 1;
        k = m + n + 2;
        tot = 0;

        rgraph = vector<vector<Edge>>(k, vector<Edge>{});

        int res;
        for (int i = 0; i < m; i++) {
            cin >> res;
            tot += res;

            auto fromEdge = Edge(i, res, rgraph[i].size());
            auto toEdge = Edge(s, 0, rgraph[s].size());

            rgraph[s].push_back(fromEdge);
            rgraph[i].push_back(toEdge);

            // cout << "rep: " << s << " " << i << " " << res << endl;
        }

        for (int i = m; i < m + n; i++) {
            cin >> res;

            auto fromEdge = Edge(t, res, rgraph[t].size());
            auto toEdge = Edge(i, 0, rgraph[i].size());

            rgraph[i].push_back(fromEdge);
            rgraph[t].push_back(toEdge);

            // cout << "tab: " << i << " " << t << " " << res << endl;
        }

        for (int i = 0; i < m; i++) {
            for (int j = m; j < m + n; j++) {
                auto fromEdge = Edge(j, 1, rgraph[j].size());
                auto toEdge = Edge(i, 0, rgraph[i].size());

                rgraph[i].push_back(fromEdge);
                rgraph[j].push_back(toEdge);

                // cout << i << " " << j << endl;
            }
        }
    }

    bool dfs(vector<int>& path, int curr) {
        // cout << "--- " << curr << endl;
        if (curr == t) return true;

        for (int i = 0; i < rgraph[curr].size(); i++) {
            auto edge = rgraph[curr][i];

            if (path[edge.to] != -1) continue;
            if (edge.res <= 0) continue;
            
            path[curr] = i;
            bool found = dfs(path, edge.to);
            if (found) return true;
        }

        return false;
    }

    void EK() {
        int tot_flow = 0;
        
        vector<int> path(k, -1);

        while (dfs(path, s)) {
            int path_flow = INT_MAX;

            for (int i = s; i != t; i = rgraph[i][path[i]].to) {
                path_flow = min(path_flow, rgraph[i][path[i]].res);
            }

            for (int i = s; i != t; i = rgraph[i][path[i]].to) {
                rgraph[i][path[i]].res -= path_flow;
                auto edge = rgraph[i][path[i]];
                rgraph[edge.to][edge.rev].res += path_flow;
            }

            tot_flow += path_flow;
            for (int i = 0; i < k; i++) path[i] = -1;
            // cout << "+++++++ flow: " << path_flow << " " << tot_flow << " " << tot << endl;
        }

        if (tot_flow < tot) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
            
            for (int i = 0; i < m; i++) {
                string s = "";
                for (int j = 0; j < rgraph[i].size(); j++) {
                    const auto& edge = rgraph[i][j];
                    if (edge.res == 0) {
                        s += to_string(edge.to - m + 1) + " ";
                    }
                }
                s.pop_back();
                cout << s << endl;
            }
        }
    }
};

int main() {
    freopen("in.txt", "r", stdin);

    auto graph = RGraph();
    graph.EK();

    return 0;
}