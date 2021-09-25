#include<vector>

using namespace std;

class Solution {

struct UnionFind
{
    vector<int> root;
    vector<int> rank;

    UnionFind(int size) {
        root = vector<int>(size);
        for (int i = 0; i < root.size(); i++) root[i] = i;

        rank = vector<int>(size, 1);
    }

    int Find(int n) {
        if (n == root[n]) return n;

        return root[n] = Find(root[n]);
    }

    void Union(int x, int y) {
        int rx = Find(x), ry = Find(y);
        if (rx != ry) {
            if (rank[rx] > rank[ry]) {
                root[ry] = rx;
            } else if (rank[rx] < rank[ry]){
                root[rx] = ry;
            } else {
                root[rx] = ry;
                rank[ry]++;
            }
        }
    }

    bool isConnected(int x, int y) {
        return Find(x) == Find(y);
    }
};


public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind U(n);

        for (auto edge : edges) U.Union(edge[0], edge[1]);

        int cnt = 0;
        for (int i = 0; i < U.root.size(); i++) {
            if (i == U.root[i]) cnt++;
        }

        return cnt;
    }
};