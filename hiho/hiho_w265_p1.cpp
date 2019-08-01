#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_root(const vector<vector<int>> &parent, vector<int> &root, int id) {
    if (root[id] == 0) root[id] = get_root(parent, root, parent[id][0]);
    return root[id];
}

bool is_valid(const vector<vector<int>> &parent) {
    vector<int> root(parent.size(), 0);
    root[1] = 1;

    for (int i = 1; i < parent.size(); i++) {
        if (get_root(parent, root, i) != 1) return false;
    }

    return true;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> parents(N + 1, vector<int>());
    vector<vector<int>> id(N + 1, vector<int>());
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;

        if (b == 1 || a > N || b > N) {
            cout << i << endl;
            return 0;
        }

        parents[b].push_back(a);
        id[b].push_back(i);
    }

//    for (int i = 1; i < parents.size(); i++) {
//        cout << i << " ";
//        for (int j = 0; j < parents[i].size(); j++) {
//            cout << parents[i][j] << " ";
//        }
//        cout << endl;
//    }

    vector<int> lines;

    for (int i = 1; i <= N; i++) {
        if (parents[i].size() > 1) {
            for (int j = 0; j < 2; j++) {
                auto parent = parents;
                parent[i] = {parents[i][j]};

                if (is_valid(parent)) {
                    lines.push_back(id[i][1 - j]);
                }
            }
        }
    }

    sort(lines.begin(), lines.end());

    for (int i = 0; i < lines.size(); i++) {
        cout << lines[i];
        if (i == lines.size() - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }

    return 0;
}

