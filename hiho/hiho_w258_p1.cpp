#include <iostream>
#include <vector>

using namespace std;

vector<int> f, in, ip, c, flg, cost, uk_ch_cnt;
vector<vector<int>> ch;
int boss;

void cal(int id) {
    int tot = 0;
    for (int i = 0; i < ch[id].size(); i++) tot += ip[ch[id][i]];

    vector<int> res(tot + 1, -1);

    res[0] = 0;

    for (int i = 0; i < ch[id].size(); i++) {
        int ch_id = ch[id][i];

        for (int j = tot; j >= 1; j--) {
            if (j - ip[ch_id] >= 0 && res[j - ip[ch_id]] != -1 && cost[ch_id] != -1) {
                int use_new = res[j - ip[ch_id]] + cost[ch_id];

                if (res[j] == -1) {
                    res[j] = use_new;
                } else {
                    res[j] = res[j] < use_new ? res[j] : use_new;
                }
            }
        }
    }

    int min_res = -1;
    for (int i = in[id]; i <= tot; i++) {
        if (min_res == -1) {
            min_res = res[i];
        } else if (res[i] != -1) {
            min_res = min_res > res[i] ? res[i] : min_res;
        }

    }
    if (min_res != -1) cost[id] = min_res + c[id];
}

int main() {
    int N;
    cin >> N;

    f = vector<int>(N + 1);
    in = vector<int>(N  + 1);
    ip = vector<int>(N + 1);
    c = vector<int>(N + 1);
    ch = vector<vector<int>>(N + 1, vector<int>());

    flg = vector<int>(N + 1, -1);
    uk_ch_cnt = vector<int>(N + 1, 0);

    cost = vector<int>(N + 1, -1);

    for (int i = 1; i <= N; i++) {
        cin >> f[i] >> in[i] >> ip[i] >> c[i];

        if (f[i] == 0) boss = i;

        ch[f[i]].push_back(i);
        uk_ch_cnt[f[i]]++;
    }

    vector<int> que;
    int cur = 0;

    for (int i = 1; i <= N; i++) {
        if (uk_ch_cnt[i] == 0 && flg[i] == -1) {
            cost[i] = c[i];

            flg[i] = 1;

            uk_ch_cnt[f[i]]--;
            if (uk_ch_cnt[f[i]] == 0) que.push_back(f[i]);
        }
    }

    while (que.size() > cur) {
        int id = que[cur];
        cur++;

        if (flg[id] != -1) continue;

//        cout << "---- " << id << endl;

        cal(id);

//        for (int i = 1; i < cost.size(); i++) cout << cost[i] << " ";
//        cout << endl;

        flg[id] = 1;

        if (id == boss) {
            cout << cost[id] << endl;
            return 0;
        }

        uk_ch_cnt[f[id]]--;
        if (uk_ch_cnt[f[id]] == 0) que.push_back(f[id]);
    }

    cout << -1 << endl;

    return 0;
}

