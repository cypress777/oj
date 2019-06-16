#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<int> order;
vector<vector<int>> storage;
int N, M;
int num = 1000;

void cal(int id, int n, unordered_set<int> g) {
    if (id == M || g.size() == N) {
        if (g.size() == N) num = min(num, n);
    } else {
        for (int i = id + 1; i < M; i++) {
            unordered_set<int> new_g = g;

            for (int j = 0; j < N; j++) {
                if (storage[i][j] >= order[j]) new_g.insert(j);
            }

            cal(i, n + 1, new_g);
        }
    }
}

int main() {
    cin >> N >> M;

    order = vector<int>(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> order[i];
    }

    storage = vector<vector<int>>(M, vector<int>(N, 0));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> storage[i][j];
        }
    }

    cal(-1, 0, unordered_set<int>());

    if (num == 1000) cout << -1 << endl;
    else cout << num << endl;

    return 0;
}