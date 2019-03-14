#include <iostream>
#include <vector>
using namespace std;
vector<int> matrix;
vector<int> path;
vector<int> ranking;
vector<int> que;
int row = 80;
int col = 80;

int id(int x, int y) {
    return 80 * x + y;
}

void up(int i) {
    while (i / 2 >= 1) {
        int j = i / 2;
        if (path[que[j]] > path[que[i]]) {
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

void down() {
    int fin = que.size() - 1;
    int i = 1;
    ranking[que[i]] = -1;
    que[i] = que[fin];
    que.pop_back();
    fin--;
    ranking[que[i]] = i;
    while (i * 2 <= fin) {
        int j = i * 2;
        if (j + 1 <= fin && path[que[j + 1]] < path[que[j]]) j++;
        if (path[que[j]] < path[que[i]]) {
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

vector<int> dx = {-1, 0, 1};
vector<int> dy = {0, 1, 0};

int main() {
    for (int i = 0; i < 6400; i++) {
        int a;
        cin >> a;
        matrix.push_back(a);
    }
    que = vector<int>(1, -1);
    ranking = vector<int>(row * col, -1);
    path = vector<int>(row * col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == 0) {
                path[id(i, j)] = matrix[id(i, j)];
                cout << i << ' ' << j << ' ' << matrix[id(i, j)] << endl;
            } else {
                path[id(i, j)] = 100000000;
            }
            que.push_back(id(i, j));
            ranking[id(i, j)] = que.size() - 1;
            up(que.size() - 1);
        }
    }

    while (que.size() > 1) {
        int i = que[1];
        ranking[i] = -1;
        int x = i / col;
        int y = i % col;
        cout << x << ' ' << y << ' ' << path[i] << endl;
        if (y == col - 1) {
            cout << path[i] << endl;
            return 0;
        }
        down();
        for (int k = 0; k < 3; k++) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx >= 0 && xx < row && yy >= 0 && yy < col) {
                int ii = id(xx, yy);
                int new_path = matrix[ii] + path[i];
                if (ranking[ii] != -1 && new_path < path[ii]) {
                    path[ii] = new_path;
                    up(ranking[ii]);
                }
            }
        }
    }

    return 0;
}