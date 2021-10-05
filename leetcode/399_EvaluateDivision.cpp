#include<vector>
#include<string>
#include<unordered_map>

using namespace std;


struct UnionFind {
    vector<int> root;
    vector<int> num;
    vector<double> vals;

    UnionFind(int size) {
        root = vector<int>(size);
        for (int i = 0; i < size; i++) root[i] = i;

        num = vector<int>(size, 1);
        vals = vector<double>(size, 1.0);
    }

    int Find(int x) {
        if (root[x] == x) return x;
        return root[x] = Find(root[x]);
    }

    void Union(int x, int y, double v) {
        int rx = Find(x), ry = Find(y);

        // cout << "------- " << x << " " << y << " " << v << endl;
        // for (auto v : vals) {
        //     cout << v << " ";
        // }
        // cout << endl;
        
        if (rx != ry) {
            if (num[rx] <= num[ry]) {                
                double factor = vals[y] * v / vals[x];
                // cout << "0000 " << y << " " << v << " " << vals[x] << " " << factor << endl;
                for (int i = 0; i < root.size(); i++) {
                    if (Find(i) == rx) {
                        // cout << i << " " << vals[i] << endl;
                        vals[i] *= factor;
                    }
                }
                
                root[rx] = ry;
                num[ry] += num[rx];
            } else {
                double factor = vals[x] / v / vals[y];
                // cout << "1111 " << x << " " << v << " " << vals[y] << " " << factor << endl;
                for (int i = 0; i < root.size(); i++) {
                    if (Find(i) == ry) {
                        // cout << i << " " << vals[i] << endl;
                        vals[i] *= factor;
                    }
                }
                
                root[ry] = rx;
                num[rx] += num[ry];
            }
        }
        
        // for (auto v : vals) {
        //     cout << v << " ";
        // }
        // cout << endl;
    }

    bool Connected(int x, int y) {
        return Find(x) == Find(y);
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> mapping;
        int cnt = 0;

        for (auto eq : equations) {
            if (mapping.find(eq[0]) == mapping.end()) {
                mapping[eq[0]] = cnt;
                cnt++;
            }

            if (mapping.find(eq[1]) == mapping.end()) {
                mapping[eq[1]] = cnt;
                cnt++;
            }
        }

        vector<double> vals(cnt, 1.0);
        UnionFind group(cnt);
        for (int i = 0; i < equations.size(); i++) {
            int id0 = mapping[equations[i][0]], id1 = mapping[equations[i][1]];
            double val = values[i];

            group.Union(id0, id1, val);
        }

        vector<double> result;
        for (auto query : queries) {
            if (mapping.find(query[0]) != mapping.end() && mapping.find(query[1]) != mapping.end()) {
                int id0 = mapping[query[0]], id1 = mapping[query[1]];
                if (!group.Connected(id0, id1)) {
                    result.push_back(-1.0);
                } else {
                    result.push_back(group.vals[id0] / group.vals[id1]);
                }
            } else {
                result.push_back(-1.0);
            }
        }

        return result;
    }
};