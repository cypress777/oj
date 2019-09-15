#include <vector>
#include <iostream>

using namespace std;

int N, M;

int main() {
    cin >> N >> M;
    cout << N <<  " " << M << endl;

    vector<int> dx{0, -1, 0, 1};
    vector<int> dy{-1, 0, 1, 0};

    int sx, sy, ex, ey;

    vector<vector<char>> maze(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];

            if (maze[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (maze[i][j] == 'T') {
                ex = i;
                ey = j;
            }
        }
    }

    vector<vector<vector<int>>> next(4, vector<vector<int>>(N, vector<int>(M)));

    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (k == 0) {
                    if (i == 0 || maze[i][j] == '#') {
                        next[k][i][j] = 0;
                    } else {
                        next[k][i][j] = next[k][i - 1][j] + 1;
                    }
                }
                if (k == 2) {
                    if (i == 0 || maze[N - 1 - i][j] == '#') {
                        next[k][N - 1 - i][j] = 0;
                    } else {
                        next[k][N - 1 - i][j] = next[k][N - i][j] + 1;
                    }
                }
                if (k == 1) {
                    if (j == 0 || maze[i][j] == '#') {
                        next[k][i][j] = 0;
                    } else {
                        next[k][i][j] = next[k][i][j - 1] + 1;
                    }
                }
                if (k == 3) {
                    if (j == 0 || maze[i][M - 1 - j] == '#') {
                        next[k][i][M - 1 - j] = 0;
                    } else {
                        next[k][i][M - 1 - j] = next[k][i][M - j] + 1;
                    }
                }
            }
        }
    }

    vector<int> que;
    vector<int> steps;
    vector<vector<vector<int>>> vst(N, vector<vector<int>>(M, vector<int>(4, -1)));
    for (int i = 0; i < 4; i++) {
        que.push_back((sx * M + sy) * 4 + i);
        steps.push_back(0);
        vst[sx][sy][i] = 1;
    }
    int front = 0;

    while (front < que.size()) {
        int cur_dir = que[front] % 4;
        int cur_y = que[front] / 4 % M;
        int cur_x = que[front] / 4 / M;
        int cur_steps = steps[front];

        if (cur_x == ex && cur_y == ey) {
            cout << cur_steps << endl;
            break;
        }

        front++;

        for (int d = 0; d < 4; d++) {
            int next_x = cur_x + dx[d] * next[d][cur_x][cur_y];
            int next_y = cur_y + dy[d] * next[d][cur_x][cur_y];

            if (vst[next_x][next_y][d] != -1) continue;
            vst[next_x][next_y][d] = 1;

            que.push_back((next_x * M + next_y) * 4 + d);
            steps.push_back(cur_steps + 1);
        }
    }
}
