#include<vector>;
#include<algorithm>;

using namespace std;

struct Edge {
  int l, x, y;  
};

bool comp(const Edge& a, const Edge& b) {
    return a.l < b.l;
}

class Solution {

struct UnionFind {
    vector<int> root;
    vector<int> rank;

    UnionFind(int size) {
        root = vector<int>(size);
        for (int i = 0; i < size; i++) root[i] = i;

        rank = vector<int>(size, 1);
    }

    int Find(int x) {
        if (x == root[x]) return x;
        return root[x] = Find(root[x]);
    }

    void Union(int x, int y) {
        int rx = Find(x), ry = Find(y);

        if (rx != ry) {
            if (rank[rx] < rank[ry]) {
                root[rx] = ry;
            } else if (rank[rx] > rank[ry]) {
                root[ry] = rx;
            } else {
                root[ry] = rx;
                rank[rx]++;
            }
        }
    }

    bool Connected(int x, int y) {
        return Find(x) == Find(y);
    }
};

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<Edge> edges;

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({.l = dist, .x = i, .y = j});
            }
        }

        sort(edges.begin(), edges.end(), comp);

        auto graph = UnionFind(points.size());

        int cnt = 0;
        int dist = 0;
        for (const auto& edge : edges) {
            if (cnt == points.size() - 1) break;

            if (!graph.Connected(edge.x, edge.y)) {
                dist += edge.l;
                graph.Union(edge.x, edge.y);
                cnt++;
            }
        }

        return dist;
    }
};