#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int MAX = 10000;
int MM;
int MOD = 1000000007;

int main() {
    MM = MAX * 1.5; // MAX * sqrt(2)

    set<int> fib;
    fib.insert(1);

    int a = 1, b = 2;
    while (b <= MM) {
        fib.insert(b);
        int tmp = a + b;
        a = b;
        b = tmp;
    }

    vector<int> dx, dy;
    for (int i = 0; i <= MM; i++) {
        for (int j = i; j <= MM; j++) {
            double dist = sqrt(pow(i, 2) + pow(j, 2));

            if (dist > MM) break;

            if (dist - int(dist) > 0) continue;

            if (fib.find(dist) == fib.end()) continue;

            dx.push_back(i);
            dy.push_back(j);
        }
    }

    vector<vector<long long>> res(MM + 1, vector<long long>(MM + 1));

    for (int i = 0; i <= MM; i++) {
        for (int j = i; j <= MM; j++) {
            if (i == 0 && j == 0) res[i][j] = 1;

            for (int k = 0; k < dx.size(); k++) {
                if (i - dx[k] >= 0 && j - dy[k] >= 0) {
                    res[i][j] = (res[i][j] + res[i - dx[k]][j - dy[k]]) % MOD;
                }

                if (dx[k] != dy[k] && i - dy[k] >= 0 && j - dx[k] >= 0) {
                    res[i][j] = (res[i][j] + res[i - dy[k]][j - dx[k]]) % MOD;
                }
            }

            if (i != j) res[j][i] = res[i][j];
        }
    }

    cout << res[10000][10000] << endl;

    return 0;
}
