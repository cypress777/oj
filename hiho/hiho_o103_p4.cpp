#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<vector<char>> map;
vector<vector<int>> flg;

int main() {
    cin >> n >> k;

    map = vector<vector<char>>(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    flg = vector<vector<int>>(n * n, vector<int>(11, -1));
    vector<int> que;
    vector<int> remain;
    vector<int> step;

    flg[0][k] = 1;
    que.push_back(0);
    remain.push_back(k);
    step.push_back(0);
    int cur = 0;

    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    while (que.size() > cur) {
        int pos = que[cur];
        int rem = remain[cur];
        int st = step[cur];
        cur++;

        int x = pos / n;
        int y = pos % n;

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            int pp = xx * n + yy;

            if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;

            int rr = rem;
            if (map[xx][yy] == '#') rr -= 1;
            if (rr < 0) continue;

            if (flg[pp][rr] != -1) continue;
            flg[pp][rr] = 1;

            if (xx == n - 1 && yy == n - 1) {
                cout << st + 1 << endl;
                return 0;
            }

            que.push_back(pp);
            remain.push_back(rr);
            step.push_back(st + 1);
//           cout << map[xx][yy] << " " << xx << " " << yy << " " << rem << " "  << st + 1 << endl;
        }
    }

    cout << -1 << endl;

    return 0;
}

