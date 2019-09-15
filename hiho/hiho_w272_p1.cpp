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
    vector<int> steps;
    vector<vector<vector<int>>> vst(N, vector<vector<int>>(M, vector<int>(4, -1)));
    for (int i = 0; i < 4; i++) {
        que_pos.push_back((sx * M + sy) * 4 + i);
        steps.push_back(0);
        vst[sx][sy][i] = 1;
    }
    int front = 0;

    while (front < que.size()) {
        int cur_dir = que[front] % 4;
        int cur_y = que[front] / 4 % M;
        int cur_x = que[front] / 4 / M;
        int cur_steps = steps[front];

        if (cur_x == ex && cur_y = ey) {
            cout << cur_steps << endl;
            break;
        }

        front++;

        for (int d = 0; d < 4; d++) {
            int next_x = cur_x + dx * next[d][cur_x][cur_y];
            int next_y = cur_y + dy * next[d][cur_x][cur_y];

            if (vst[next_x][next_y][d] != -1) continue;

            que.push_back((next_x * M + next_x) * 4 + d);
            steps.push_back(cur_steps + 1);
        }
    }
}
