#include <iostream>
#include <vector>

using namespace std;

vector<int> f, in, ip, c, flg, cost, ch_cnt;
vector<vector<int>> ch;

int main() {
    int N;
    cin >> N;

    f = vector<int>(N + 1);
    in = vector<int>(N  + 1);
    ip = vector<int>(N + 1);
    c = vector<int>(N + 1);
    flg = vector<int>(N + 1, -1);
    cost = vector<int>(N + 1);
    ch = vector<vector<int>>(N + 1, vector<int>());
    ch_cnt = vector<int>(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> f[i] >> in[i] >> ip[i] >> c[i];
        ch[f[i]].push_back(i);
        ch_cnt[i]++;
    }

    vector<int> que;
    int cur = 0;

    for (int i = 1; i <= N; i++) {
        if (ch_cnt[i] == 0 && flg[i] == -1) {
            cost[i] = c[i];
            flg[i] = 1;
            ch_cnt[f[i]]--;
            if (ch_cnt[f[i]] == 0) que.push_back(f[i]);
        }
    }

    while (que.size() > cur) {
        int id = que[cur];
        cur++;

        cal()
    }

    return 0;
}

