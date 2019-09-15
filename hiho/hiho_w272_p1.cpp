#include <vector>
#include <iostream>

using namespace std;

int N, M;

int main() {
    cin >> N >> M;

    vector<int> dx{0, 1, 0, -1};
    vector<int> dy{1, 0, -1, 0};

    int sx, sy, ex, ey;

    vector<vector<int>> maze(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];

            if (maze[i][j] == 'S') sx = i, sy = j;
            if (maze[i][j] == 'T') ex = i, ey = j;
        }
    }

    vector<vector<vector<int>>> next(4, vector<vector<int>>(N, vector<int>(M)));

    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {

            }
        }
    }

    vector<int> que;
    vector<vector<vector<int>>> vst(N, vector<vector<int>>(M, vector<int>(4, -1)));
    for (int i = 0; i < 4; i++) {
        que_pos.push_back((sx * M + sy) * 4 + i);
        vst[sx][sy][i] = 1;
    }
    int front = 0;

    while (front < que.size()) {

    }
}
