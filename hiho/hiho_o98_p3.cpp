#include <vector>
#include <iostream>

using namespace std;

int N, M;

vector<vector<int>> last_one;
vector<vector<int>> last_two;
vector<vector<int>> map;
int MM = 1000000;

int main() {
    cin >> N >> M;

    last_one = vector<vector<int>>(N, vector<int>(M, -1));
    last_two = vector<vector<int>>(N, vector<int>(M, -1));
    map = vector<vector<int>>(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == '1') {
                map[i][j] = 1;
                last_one[i][j] = i;
            } else if (s[j] == '2') {
                map[i][j] = 2;
                last_two[i][j] = i;
            }
            if (i > 0 && last_one[i][j] == -1) last_one[i][j] = last_one[i - 1][j];
            if (i > 0 && last_two[i][j] == -1) last_two[i][j] = last_two[i - 1][j];
        }
    }

    int res = MM;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1) {
                for (int k = 0;  k < M; k++) {
                    if (last_two[i][k] != -1) {
                        int dist = abs(i - last_two[i][k]) + abs(j - k) + 1;
                        if (dist < res) res = dist;
                    }
                }
            } else if (map[i][j] == 2) {
                for (int k = 0;  k < M; k++) {
                    if (last_one[i][k] != -1) {
                        int dist = abs(i - last_one[i][k]) + abs(j - k) + 1;
                        if (dist < res) res = dist;
                    }
                }
            }
        }
    }

    cout << res << endl;
}