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
                up[i][j] += ori[i - 1][j];
            }
        }
    }

    vector<vector<int>> left(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            left[i][j] = ori[i][j];
            if (j > 0) {
                left[i][j] += ori[i][j - 1];
            }
        }
    }

    vector<vector<vector<int>>> up_cnt(N, vector<vector<int>>(N, vector<int>(N + 1)));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 1; k <= j + 1; k++) {
                up_cnt[i][j][k] = 1;
                if (j > 0 &&
                    up[i][j] - up[i - k][j] == up[i][j - 1] - up[i - k][j - 1]) up_cnt[i][j][k] += up_cnt[i][j - 1][k];
            }
        }
    }

    vector<vector<vector<int>>> left_cnt(N, vector<vector<int>>(N, vector<int>(N + 1)));


    return 0;
}

