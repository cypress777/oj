#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> map;
vector<vector<int>> l, r, u, d;

int main() {
    int N, M;
    cin >> N >> M;

    map = vector<vector<char>>(N + 1, vector<char>(M + 1));
    l = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
    r = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
    u = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
    d = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'B') {
                l[i][j] = 1;
                u[i][j] = 1;
            } else {
                if (j - 1 >= 0) l[i][j] = l[i][j - 1];
                if (i - 1 >= 0) u[i][j] = u[i - 1][j];
            }

            if (map[N - i - 1][M - j - 1] == 'B') {
                r[N - i - 1][M - j - 1] = 1;
                d[N - i - 1][M - j - 1] = 1;
            } else {
                if (M - j < M) r[N - i - 1][M - j - 1] = r[N - i - 1][M - j];
                if (N - i < N) d[N - i - 1][M - j - 1] = d[N - i][M - j - 1];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'B') {
                cout << 'B';
            } else {
                cout << l[i][j] + r[i][j] + u[i][j] + d[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}

