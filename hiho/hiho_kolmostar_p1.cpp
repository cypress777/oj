#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> left_cnt;
vector<vector<int>> up_cnt;
vector<vector<int>> size;

int main() {
    cin >> N >> M;

    map = vector<vector<int>>(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    left_cnt = vector<vector<int>>(N, vector<int>(M, 0));
    up_cnt = vector<vector<int>>(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j == 0 || map[i][j - 1] == 0) {
                left_cnt[i][j] = map[i][j];
            } else {
                left_cnt[i][j] = left_cnt[i][j - 1] + map[i][j];
            }

            if (i == 0 || map[i - 1][j] == 0) {
                up_cnt[i][j] = map[i][j];
            } else {
                up_cnt[i][j] = up_cnt[i - 1][j] + map[i][j];
            }
        }
    }

    int max_size = 0;
    size = vector<vector<int>>(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 || j == 0) {
                size[i][j] = map[i][j];
            } else {
                if (map[i][j] == 0) continue;
                size[i][j] = min(min(size[i - 1][j - 1] + 1, up_cnt[i][j]), min(size[i - 1][j - 1] + 1, left_cnt[i][j]));
            }
            if (size[i][j] > max_size) max_size = size[i][j];
        }
    }

    cout << max_size * max_size << endl;

    return 0;
}

