#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> map(N, vector<int>(N, 0));
    vector<int> vst(N * N, -1);

    vector<int> que{};
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++) {
            map[i][j] = s[j] - '0';
            if (map[i][j] == 0) {
                vst[i * N + j] = 1;
                que.push_back(i * N + j);
            }
        }
    }

    vector<int> dx{1, 0, -1, 0};
    vector<int> dy{0, 1, 0, -1};

    int r = 0, f = que.size() - 1;
    int max = 0;
    while (r <= f) {
        int id = que[r];
        int x = id / N;
        int y = id % N;
        r++;
        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx < N && xx >= 0 && yy < N && yy >= 0) {
                int iid = xx * N + yy;
                if (vst[iid] == -1) {
                    vst[iid] = 1;
                    map[xx][yy] = map[x][y] + 1;
                    if (map[xx][yy] > max) max = map[xx][yy];
                    que.push_back(iid);
                    f++;
                }
            }
        }
    }
    cout << max << endl;

    return 0;
}

