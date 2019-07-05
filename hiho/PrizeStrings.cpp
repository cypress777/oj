#include <iostream>
#include <vector>

using namespace std;

int MM = 30;

int main() {
    vector<vector<long long>> res(MM + 1, vector<long long>(7, 0));

    res[1][0] = 1;
    res[1][1] = 1;
    res[1][6] = 1;

    long long cnt = 0;

    cout << 1 << ": ";
    for (int j = 0; j <= 6; j++) {
        cout << res[1][j] << " ";
        cnt += res[1][j];
    }
    cout << cnt << endl;

    for (long long i = 2; i <= MM; i++) {
        for (long long j = 0; j < 3; j++) {
            res[i][0] += res[i - 1][j];
        }

        res[i][1] = res[i - 1][0];

        res[i][2] = res[i - 1][1];

        for (long long j = 0; j < 4; j++) {
            res[i][3] += res[i - 1][3 + j];
        }

        res[i][4] = res[i - 1][3] + res[i - 1][6];

        res[i][5] = res[i - 1][4];

        for (long long j = 0; j < 3; j++) {
            res[i][6] += res[i - 1][j];
        }


        cnt = 0;
        cout << i << ": ";
        for (int j = 0; j <= 6; j++){
            cout << res[i][j] << " ";
            cnt += res[i][j];
        }
        cout << cnt << endl;
    }
}

