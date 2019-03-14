#include <iostream>
#include <vector>
using namespace std;

vector<int> matrix;
vector<int> path;
vector<int> que;
vector<int> ranking;

int row = 80;
int col = 80;

void down() {
    int i = 1;
    while (i * 2 < que.size()) {
        int j = i * 2;
        if (j + 1 < que.size() - 1 && path[que[j + 1]] < path[que[j]]) j++;
        if (path[que[i]] > path[que[j]]) {
            int tmp = que[i];
            que[i] = que[j];
            que[j] = tmp;
            ranking[que[i]] = i;
            ranking[que[j]] = j;
            i = j;
        } else {
            break;
        }
    }
}

void up(int i) {
    while (i / 2 >= 1) {
        int  j = i / 2;
        if (path[que[i]] < path[que[j]]) {
            int tmp = que[i];
            que[i] = que[j];
            que[j] = tmp;
            ranking[que[i]] = i;
            ranking[que[j]] = j;
            i = j;
        } else {
            break;
        }
    }
}

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

int main() {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            int a;
            cin >> a;
            matrix.push_back(a);
        }
    }

    path = vector<int>(row * col);
    ranking = vector<int>(row * col);
    que = vector<int>(1, 0);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 && j == 0) {
                path[i * col + j] = matrix[i * col + j];
            } else {
                path[i * col + j] = 100000000;
            }
            que.push_back(i * col + j);
            ranking[i * col  + j] = que.size() - 1;
            up(que.size() - 1);
        }
    }

    while (que.size() > 1) {
        int id = que[1];
        ranking[id] = -1;
        int x = id / col;
        int y = id % col;
        if (x == row - 1 && y == col  - 1) {
            cout << path[id] << endl;
            return 0;
        }
        que[1] = que[que.size() - 1];
        ranking[que[1]] = 1;
        que.pop_back();
        down();

        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            int iid = xx * col + yy;
            if (xx >= 0 && xx < col && yy >= 0 && yy < row) {
                int new_path = path[id] + matrix[iid];
                if (ranking[iid] != -1 && new_path < path[iid]) {
                    path[iid] = new_path;
                    up(ranking[iid]);
                }
            }
        }
    }

    return 0;
}