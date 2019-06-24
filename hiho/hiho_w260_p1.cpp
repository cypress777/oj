#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> map(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    vector<vector<int>> left(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            left[i][j] = map[i][j];
            if (j > 0) left[i][j] += left[i][j - 1];
        }
    }

    int max_vol = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int m = 0, n = 0;
            int tot = left[0][j] - left[0][i] + map[0][i];
            int vol = j - i + 1;
            while (m < M) {
                if (tot <= K) {
                    max_vol = max(max_vol, vol);
                    n++;
                    if (n >= M) break;
                    vol += j - i + 1;
                    tot += left[n][j] - left[n][i] + map[n][i];
                } else {
                    tot -= left[m][j] - left[m][i] + map[m][i];
                    vol -= j - i + 1;
                    m++;
                }
            }
        }
    }

    if (max_vol <= 0) max_vol = -1;
    cout << max_vol << endl;

    return 0;
}

