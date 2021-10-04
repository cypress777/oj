#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

struct UnionFind {
    vector<int> num;
    vector<int> root;

    UnionFind(int size) {
        root = vector<int>(size);
        for (int i = 0; i < size; i++) root[i] = i;
        num = vector<int>(size, 1);
    }

    int Find(int x) {
        if (x == root[x]) return x;
        return root[x] = Find(root[x]);
    }

    void Union(int x, int y) {
        int rx = Find(x), ry = Find(y);
        if (rx != ry) {
            if (num[rx] >= num[ry]) {
                root[ry] = rx;
                num[rx] += num[ry];
            } else {
                root[rx] = ry;
                num[ry] += num[rx];
            }
        }
    }

    bool Connected(int x, int y) {
        return Find(x) == Find(y);
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind group(s.size());

        for (auto pair : pairs) {
            group.Union(pair[0], pair[1]);
        }

        vector<vector<int>> ids(s.size(), vector<int>{});

        for (int i = 0; i < s.size(); i++) {
            ids[group.Find(i)].push_back(i);
        }

        vector<vector<int>> new_ids = ids;
        string new_s = s;
        for (int i = 0; i < ids.size(); i++) {
            
            sort(new_ids[i].begin(), new_ids[i].end(), [&](int x, int y){return s[x] - 'a' < s[y] - 'a';});
            
            for (int j = 0; j < ids[i].size(); j++) {
                new_s[ids[i][j]] = s[new_ids[i][j]];
            }
        }

        return new_s;
    }
};