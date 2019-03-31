#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<int> tree;
vector<vector<int>> child;
vector<int> child_size;

int cal_child_size(int id) {
    if (child_size[id] != -1) return child_size[id];
    if (child[id].empty()) {
        child_size[id] = 1;
        return 1;
    }

    int res = 1;
    for (int i = 0; i < child[id].size(); i++) {
        res += cal_child_size(child[id][i]);
    }
    child_size[id] = res;
    return child_size[id];
}

int main(){
    cin >> N;

    tree = vector<int>(N + 1);
    child = vector<vector<int>>(N + 1, vector<int>());
    child_size = vector<int>(N + 1, -1);

    int root = 0;
    for (int i = 1; i <= N; i++) {
        cin >> tree[i];
        if (tree[i] == 0) root = i;
        child[tree[i]].push_back(i);
    }

    int total = cal_child_size(1);

    vector<int> res;
    for (int i = 1; i <= N; i++) {
        bool vailable = true;

        int all_child_size = 1;
        for (auto ch : child[i]) {
            int other = child_size[ch];
            all_child_size += other;
            if (total - other <= other) {
                vailable = false;
                break;
            }
        }

        if (vailable && total - all_child_size >= all_child_size) vailable = false;

        if (vailable) res.push_back(i);
    }

    sort(res.begin(), res.end());

    cout << res.size() << endl;
    for (int n : res) cout << n << endl;

    return 0;
}