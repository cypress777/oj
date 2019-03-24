#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> up_sum;
vector<vector<int>> down_sum;
vector<vector<int>> right_sum;
vector<vector<int>> left_sum;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    map = vector<vector<int>>(N, vector<int>(M, -1));
    up_sum = vector<vector<int>>(N, vector<int>(M, 0));
    down_sum = vector<vector<int>>(N, vector<int>(M, 0));
    right_sum = vector<vector<int>>(N, vector<int>(M, 0));
    left_sum = vector<vector<int>>(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 1; j < N; j++) {
            if (map[j][i] == map[j - 1][i]) up_sum[j][i] = up_sum[j - 1][i] + 1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (map[i][j] == map[i][j - 1]) left_sum[i][j] = left_sum[i][j - 1] + 1;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = N - 2; j >= 0; j--) {
            if (map[j][i] == map[j + 1][i]) down_sum[j][i] += down_sum[j + 1][i] + 1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = M - 2; j >= 0; j--) {
            if (map[i][j] == map[i][j + 1]) right_sum[i][j] += right_sum[i][j + 1] + 1;
        }
    }

    for (int i = 0; i < Q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int w = abs(c2 - c1);
        int h = abs(r2 - r1);

        if (r1 == r2 && left_sum[r2][max(c1, c2)] >= w - 1 || c1 == c2 && up_sum[max(r1, r2)][c2] >= h - 1) {
            cout << 0 << endl;
            continue;
        }
        if (r1 != r2 && c1 != c2) {
            if (c2 > c1 && r2 > r1 && (left_sum[r1][c2] >= w - 1 && down_sum[r1][c2] >= h - 1 ||
                                       right_sum[r2][c1] >= w - 1 && up_sum[r2][c1] >= h - 1) ||
                c2 > c1 && r1 > r2 && (right_sum[r2][c1] >= w - 1 && down_sum[r2][c1] >= h - 1 ||
                                       left_sum[r1][c2] >= w - 1 && up_sum[r1][c2] >= h - 1) ||
                c1 > c2 && r2 > r1 && (right_sum[r1][c2] >= w - 1 && down_sum[r1][c2] >= h - 1 ||
                                       left_sum[r2][c1] >= w - 1 && up_sum[r2][c1] >= h - 1) ||
                c1 > c2 && r1 > r2 && (left_sum[r2][c1] >= w - 1 && down_sum[r2][c1] >= h - 1 ||
                                       right_sum[r1][c2] >= w - 1 && up_sum[r1][c2] >= h - 1)) {
                cout << 1 << endl;
                continue;
            }
        }
        int c_max = right_sum[(c1 < c2 ? r1 : r2)][(c1 < c2 ? c1 : c2)] + (c1 < c2 ? c1 : c2);
        c_max = min(M - 1, c_max);
        int c_min = (c1 < c2 ? c2 : c1) - left_sum[(c1 < c2 ? r2 : r1)][(c1 < c2 ? c2 : c1)];
        c_min = max(0, c_min);
        int r_max = down_sum[(r1 < r2 ? r1 : r2)][(r1 < r2 ? c1 : c2)] + (r1 < r2 ? r1 : r2);
        r_max = min(N - 1, r_max);
        int r_min = (r1 < r2 ? r2 : r1) - up_sum[(r1 < r2 ? r2 : r1)][(r1 < r2 ? c2 : c1)];
        r_min = max(0, r_min);
        if (c_max >= c_min || r_max >= r_min) {
            cout << 2 << endl;
            continue;
        }
        cout << -1 << endl;
    }

    return 0;
}