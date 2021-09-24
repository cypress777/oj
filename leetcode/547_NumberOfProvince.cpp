#include<vector>;

using namespace std;


class Solution {

struct UnionFind {
    vector<int> root;
    vector<int> rank;

public:
    UnionFind(int size): root(size) {
        rank = vector<int>(size, 1);
        for (int i = 0; i < root.size(); i++) {
            root[i] = i;
        }
    }
    
    int Find(int n) {
        if (root[n] == n) {
            return n;
        }
        return root[n] = Find(root[n]);
    }

    void Union(int x, int y) {
        auto root_x = Find(x);
        auto root_y = Find(y);

        if (root_x != root_y) {
            if (rank[root_x] > rank[root_y]) {
                root[root_y] = root_x;
            } else if (rank[root_x] < rank[root_y]) {
                root[root_x] = root_y;
            } else {
                root[root_x] = root_y;
                rank[root_y] += 1;
            }
        }
    }

    bool IsConnected(int x, int y) {
        return Find(x) == Find(y);
    }
};

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        auto groups = UnionFind(isConnected.size());

        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = i + 1; j < isConnected[i].size(); j++) {
                if (isConnected[i][j]) groups.Union(i, j);
            }
        }

        int cnt = 0;
        for (int i = 0; i < groups.root.size(); i++) {
            if (groups.root[i] == i) cnt++;
        }

        return cnt;
    }
};