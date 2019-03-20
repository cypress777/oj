#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M, K, a, b, c, d;

int status_convert(int x, int y, int sta, const vector<vector<int>> &keys) {
    for (int i = 0; i < K; i++) {
        if (x == keys[i][0]  && y == keys[i][1]) sta = sta | int(pow(2, i));
    }
    return sta;
}

int encode(int x, int y, int sta) {
    return sta * N * M + x * M + y;
}

void decode(int id, int &x, int &y, int &sta) {
    sta = id / (N * M);
    x = id % (N * M) / M;
    y = id % (N * M) % M;
}

bool accessible(int x, int y, int sta, const vector<vector<char>> &matrix, const vector<vector<int>> &locks) {
    if (x < 0 || x >= N || y < 0 || y >= M || sta > 32) return false;
    if (matrix[x][y] == '.') return true;
    if (matrix[x][y] == '#') return false;
    for (int i = 0; i < K; i++) {
        if (x == locks[i][0] && y == locks[i][1]) {
            if ((sta & int(pow(2, i))) > 0) {
                return true;
            } else {
                return false;
            }
        }
    }
}

int main() {
    vector<int> dx{-1, 0, 1, 0};
    vector<int> dy{0, -1, 0, 1};
    cin >> N >> M >> K >> a >> b >> c >> d;

    vector<vector<char>> matrix(N, vector<char>(M, '.'));
    vector<vector<int>> locks(K, vector<int>(2, -1));
    vector<vector<int>> keys(K, vector<int>(2, -1));
    vector<int> vst(N * M * 32, 0);
    vector<int> path(N * M * 32, -1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char sym;
            cin >> sym;
            matrix[i][j] = sym;
            if (sym != '.' && sym != '#') {
                locks[sym - 'A'][0] = i;
                locks[sym - 'A'][1] = j;
            }
        }
    }

    for (int i = 0; i < K; i++) {
        cin >> keys[i][0] >> keys[i][1];
    }

    int sta = status_convert(a, b, 0, keys);
    int start = encode(a, b, sta);
    vector<int> que{};
    que.push_back(start);
    vst[start] = -1;
    path[start] = 0;
    int r = 0;
    while (r < que.size()) {
        int id = que[r];
        r++;
        int x, y, sta;
        decode(id, x, y, sta);
        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            int staa = status_convert(xx, yy, sta, keys);
            if (accessible(xx, yy, staa, matrix, locks)) {
                int idd = encode(xx, yy, staa);
                if (vst[idd] != -1) {
                    vst[idd] = -1;
                    que.push_back(idd);
                    path[idd] = path[id] + 1;
                    if (xx == c and yy == d) {
                        cout << path[idd] << endl;
                        return 0;
                    }
                }
            }            
        }
    }
    cout << -1 << endl;
    return 0;
}