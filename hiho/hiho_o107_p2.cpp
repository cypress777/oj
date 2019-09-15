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

    vector<vector<int>> up(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            up[i][j] = ori[i][j];
            if (i > 0) {
                up[i][j] += up[i - 1][j];
            }
        }
    }

    vector<vector<int>> left(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            left[i][j] = ori[i][j];
            if (j > 0) {
                left[i][j] += left[i][j - 1];
            }
        }
    }

    vector<vector<int>> left_up(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            left_up[i][j] = ori[i][j];
            if (j > 0 && i > 0) {
                left_up[i][j] += left_up[i - 1][j - 1];
            }
        }
    }

    vector<vector<int>> right_up(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            right_up[i][j] = ori[i][j];
            if (j < N - 1 && i > 0) {
                right_up[i][j] += right_up[i - 1][j + 1];
            }
        }
    }

    vector<vector<vector<int>>> up_cnt(N, vector<vector<int>>(N, vector<int>(N + 1)));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 1; k <= i + 1; k++) {
                up_cnt[i][j][k] = 1;
                if (j > 0 &&
                    up[i][j] - (i >= k ? up[i - k][j] : 0) ==
                    up[i][j - 1] - (i >= k ? up[i - k][j - 1] : 0)) up_cnt[i][j][k] += up_cnt[i][j - 1][k];
            }
        }
    }

    vector<vector<vector<int>>> left_cnt(N, vector<vector<int>>(N, vector<int>(N + 1)));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 1; k <= j + 1; k++) {
                left_cnt[i][j][k] = 1;
                if (i > 0 &&
                    left[i][j] - (j >= k ? left[i][j - k] : 0) ==
                    left[i - 1][j] - (j >= k ? left[i - 1][j - k] : 0)) left_cnt[i][j][k] += left_cnt[i - 1][j][k];
            }
        }
    }

    int tot = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 1; k <= min(i + 1, j + 1); k++) {
                if (up_cnt[i][j][k] < k || left_cnt[i][j][k] < k) continue;

                int up_val = up[i][j] - (i >= k ? up[i - k][j] : 0);
                int left_val = left[i][j] - (j >= k ? left[i][j - k] : 0);
                int left_up_val = left_up[i][j] - (i >= k && j >= k ? left_up[i - k][j - k] : 0);
                int right_up_val = right_up[i][j - k + 1] - (i >= k && j < N - 1 ? right_up[i - k][j + 1] : 0);
                if (up_val != left_val || up_val != left_up_val || up_val != right_up_val) continue;

//                cout << i << " " << j << " " << k << endl;
                tot++;
            }
        }
    }

    cout << tot << endl;

    return 0;
}

