#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> weather(N);
    for (int i = 0; i < N; i++) {
        cin >> weather[i];
    }

    vector<vector<int>> vst(M, vector<int>(N, 0));
    if (weather[0][0] == 'O') vst[0][0] = 1;

    for (int i = 1; i < M; i++) {
        for (int j = 0; j < N; j++) {
//            cout << i << " " << j << " ";
//            cout << weather[j][i] << " ";

            if ((j == 0 || (j > 0 && vst[i - 1][j - 1] > 0) || vst[i - 1][j] > 0) && weather[j][i] == 'O') {
                vst[i][j] = 1;
            }

//            cout << vst[i][j] << endl;
        }

        if (vst[i][N - 1] > 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}

