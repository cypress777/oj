#include <vector>
#include <iostream>

using namespace std;

int N, M;

int main() {
    cin >> N >> M;

    vector<int> dx{-1, 0, 1, 0};
    vector<int> dy{0, -1, 0, 1};

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
                    if (i == 0 || maze[i - 1][j] == '#') {
                        next[k][i][j] = 0;
                    } else {
                        next[k][i][j] = next[k][i - 1][j] + 1;
                    }
                }
                if (k == 2) {
                    if (i == 0 || maze[N - i][j] == '#') {
                        next[k][N - 1 - i][j] = 0;
                    } else {
                        next[k][N - 1 - i][j] = next[k][N - i][j] + 1;
                    }
                }
                if (k == 1) {
                    if (j == 0 || maze[i][j - 1] == '#') {
                        next[k][i][j] = 0;
                    } else {
                        next[k][i][j] = next[k][i][j - 1] + 1;
                    }
                }
                if (k == 3) {
                    if (j == 0 || maze[i][M - j] == '#') {
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

//    cout << sx << " " << sy << " " << ex << " " << ey << endl;
    while (front < que.size()) {
        const int cur_dir = que[front] % 4;
        const int cur_y = que[front] / 4 % M;
        const int cur_x = que[front] / 4 / M;
        const int cur_steps = steps[front];

//        cout << "----- " << cur_x << " " << cur_y << " " << cur_dir << " " << cur_steps << endl;
        if (cur_x == ex && cur_y == ey) {
            cout << cur_steps - 1 << endl;
            return 0;
        }

        front++;

        for (int d = 0; d < 4; d++) {
            if (d == cur_dir) continue;
            if (next[d][cur_x][cur_y] == 0) continue;

            int next_x = cur_x + dx[d] * next[d][cur_x][cur_y];
            int next_y = cur_y + dy[d] * next[d][cur_x][cur_y];

            if ((cur_x == next_x && next_x == ex && ey <= max(next_y, cur_y) && ey >= min(next_y, cur_y)) ||
                (cur_y == next_y && next_y == ey && ex <= max(next_x, cur_x) && ex >= min(next_x, cur_x))) {
                cout << cur_steps << endl;
                return 0;
            }

            if (vst[next_x][next_y][d] != -1) continue;
            vst[next_x][next_y][d] = 1;

//            cout << dx[d] << " " << dy[d] << " " << next[d][cur_x][cur_y] << " " << next_x << " " << next_y << " " << d << endl;
            que.push_back((next_x * M + next_y) * 4 + d);
            steps.push_back(cur_steps + 1);
        }
    }
    cout << int(-1) << endl;
}
