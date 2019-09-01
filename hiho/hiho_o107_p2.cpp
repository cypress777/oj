#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> ori(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ori[i][j];
        }
    }

    vector<vector<int>> left(N, vector<int>(N));
    vector<vector<int>> up(N, vector<int>(N));
    vector<vector<int>> left_up(N, vector<int>(N));
    vector<vector<int>> right_up(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            left[i][j] = ori[i][j];
            if (j > 0) left[i][j] += left[i][j - 1];

            up[i][j] = ori[i][j];
            if (i > 0) up[i][j] += up[i - 1][j];

            left_up[i][j] = ori[i][j];
            if (i > 0 && j > 0) left_up[i][j] += left_up[i - 1][j - 1];

            right_up[i][N - 1 - j] = ori[i][N - 1 - j];
            if (i > 0 && j > 0) right_up[i][N - 1 - j] += right_up[i - 1][N - j];
        }
    }

    vector<vector<vector<int>>> left_res(N, vector<vector<int>>(N, vector<int>(N + 1, 1)));
    vector<vector<vector<int>>> up_res(N, vector<vector<int>>(N, vector<int>(N + 1, 1)));
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int l = 1; l <= j + 1; l++) {
                if (left[i][j] - (j >= l ? left[i][j - l] : 0) == left[i - 1][j] - (j >= l ? left[i - 1][j - l] : 0)) {
                    left_res[i][j][l] += left_res[i - 1][j][l];
                }

                if (up[j][i] - (j >= l ? up[j - l][i] : 0) == up[j][i - 1] - (j >= l ? up[j - l][i - 1] : 0)) {
                    up_res[j][i][l] += up_res[j][i - 1][l];
                }
            }
        }
    }

    int tot = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int l = 1; l <= min(i + 1, j + 1); l++) {
//                cout << "----- " << i << " " << j << " " << l << endl;
//                cout << left_res[i][j][l] << endl;
//                cout << up_res[i][j][l] << endl;
//                cout << left_up[i][j] << " " << (i >= l && j >= l ? left_up[i - l][j - l] : 0) << endl;
//                cout << right_up[i][j - l + 1] << " " << (i >= l ? right_up[i - l][j + 1] : 0) << endl;
                if (left_res[i][j][l] >= l &&
                    up_res[i][j][l] >= l &&
                    (left_up[i][j] - (i >= l && j >= l ? left_up[i - l][j - l] : 0)) ==
                    (right_up[i][j - l + 1] - (i >= l ? right_up[i - l][j + 1] : 0))) {
                    tot++;
                }
            }
        }
    }

    cout << tot << endl;

    return 0;
}

