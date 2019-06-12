#include <iostream>
#include <vector>

using namespace std;

int N = 15;
vector<vector<long long>> way;

int main() {
    way = vector<vector<long long>>(N + 1, vector<long long>(N + 1, 0));

    way[1][1] = 1;
    way[1][0] = 1;

    for (long long i = 2; i <= N; i++) {
        for (long long j = 0; j <= N; j++) {
            way[i][j] = (j == 0 ? 0 : way[i - 1][j - 1]) + way[i - 1][j] * i;
        }
    }

    long long tot = 0;
    long long win = 0;
    for (long long i = 0; i <= N; i++) {
        tot += way[N][i];
        if (i > (long long)(N / 2)) win += way[N][i];
    }

    cout << win << " " << tot << " " << tot / win << endl;
}