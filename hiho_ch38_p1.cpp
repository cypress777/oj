#include <vector>
#include <iostream>

using namespace std;

int n;
vector<int> seq;
vector<vector<vector<int>>> res;
string a = "cute";
string b = "etuc";

int main() {
    string line;
    cin >> n;
    cin >> line;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            if (line[i] == a[j]) {
                seq.push_back(j);
                break;
            }
        }
    }

    res = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(4, vector<int>(4, -1)));
    res[0][3][0] = 0;

    for (int k = 1; k < n + 1; k++) {
        int t = seq[k - 1];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                res[k][i][j] = res[k - 1][i][j];
                if (i == t) {
                    int addt = -1;
                    if (res[k - 1][(i + 3) % 4][j] != -1) addt = res[k - 1][(i + 3) % 4][j] + 1;
                    if (addt > res[k][i][j]) res[k][i][j] = addt;
                }
                if (j == t) {
                    int addt = -1;
                    if (res[k - 1][i][(j + 1) % 4] != -1) addt = res[k - 1][i][(j + 1) % 4] + 1;
                    if (addt > res[k][i][j]) res[k][i][j] = addt;
                }
            }
        }
    }

    cout << res[n][3][0] << endl;

    return 0;
}