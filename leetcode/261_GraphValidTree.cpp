#include<vector>;
#include<unordered_set>;
using namespace std;


class Solution {
public:
    struct UnionFind
    {
        public:
            vector<int> root;
            vector<int> rank;

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
    

    bool validTree(int n, vector<vector<int>>& edges) {
        auto dis_set = UnionFind(n);

        if (n - 1 != edges.size()) return false;

        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i][0], y = edges[i][1];

            if (dis_set.IsConnected(x, y)) return false;

            dis_set.Union(x, y);
        }

        int cnt = 0;
        for (int i = 0; i < dis_set.root.size(); i++) {
            if (dis_set.root[i] == i) cnt++;
            if (cnt > 1) return false;
        }

        return true;
    }
};