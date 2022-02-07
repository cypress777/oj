#include<vector>
#include<algorithm>
using namespace std;


bool comp(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

struct UnionFind {
    vector<int> root;
    vector<int> num;

    UnionFind(int size) {
        root = vector<int>(size);
        for (int i = 0; i < size; i++) root[i] = i;
        
        num = vector<int>(size, 1);
    }

    int Find(int x) {
        if (root[x] == x) return x;
        return root[x] = Find(root[x]);
    }

    void Union(int x, int y) {
        int rx = Find(x), ry = Find(y);
        if (rx == ry) return;

        if (num[rx] < num[ry]) {
            root[rx] = ry;
            num[ry] += num[rx];
        } else if (num[rx] > num[ry]) {
            root[ry] = rx;
            num[rx] += num[ry];
        } else {
            root[ry] = rx;
            num[rx] += num[ry];
        }
    }
    
    int UnionSize(int x) {
        return num[Find(x)];
    }

    bool Connected(int x, int y) {
        return Find(x) == Find(y);
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), comp);

        UnionFind friend_circle(n);

        for (auto log : logs) {
            if (friend_circle.Connected(log[1], log[2])) continue;

            friend_circle.Union(log[1], log[2]);
            auto union_size = friend_circle.UnionSize(log[1]);

            // cout << "====== " << log[1] << " " << log[2] << " " << union_size << endl;
            if (union_size == n) return log[0];
        }

        return -1;
    }
};