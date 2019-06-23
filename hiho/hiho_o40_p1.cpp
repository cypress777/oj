#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    vector<vector<int>> left(N, vector<int>(M));
    vector<vector<int>> up(N, vector<int>(M));
    vector<vector<int>> leftup(N, vector<int>(M));
    vector<vector<int>> rightup(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j >= 2) {
                left[i][j] = map[i][j - 2] + map[i][j - 1] + map[i][j];
            }

            if (i >= 2) {
                up[i][j] = map[i - 2][j] + map[i - 1][j] + map[i][j];
            }

            if (i >= 2 && j >= 2) {
                leftup[i][j] = map[i - 2][j - 2] + map[i - 1][j - 1] + map[i][j];
            }

            if (i >= 2 && j < M - 2) {
                rightup[i][j] = map[i][j] + map[i - 1][j + 1] + map[i - 2][j + 2];
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i >= 2 && j >= 2) {
                if (left[i][j] != left[i - 1][j] || left[i][j] != left[i - 2][j]) continue;
                if (up[i][j] != up[i][j - 1] || up[i][j] != up[i][j - 2]) continue;
                if (left[i][j] != leftup[i][j]) continue;
                if (left[i][j] != rightup[i][j - 2]) continue;
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}

