#include <iostream>
#include <vector>

using namespace std;

vector<int> ori;
vector<int> r_sockets;
vector<int> l_sockets;
int MM = 1000000007;
vector<vector<int>> cal_map;

void r2l() {
    int val = 0;
    int r_cnt = 0;

    for (int i = ori.size() - 1; i >= 0; i++) {
        val += ori[i];
        if (ori[i] == 1) {
            if (val > 0) {
                r_cnt++;
                val = 0;
            }
            r_sockets.push_back(r_cnt);
        }
    }
}

void l2r() {
    int val = 0;
    int l_cnt = 0;

    for (int i = 0; i < ori.size(); i++) {
        val += ori[i];
        if (ori[i] == -1) {
            if (val < 0) {
                l_cnt++;
                val = 0;
            }
            l_sockets.push_back(l_cnt);
        }
    }
}

int fast_pow(int base, int pow) {

}

int permutation(int obj) {

}

int cal(int slot, int obj) {
    return fast_pow(slot, obj) / permutation(obj) % MM;
}

int solve(vector<int> socket) {
    int cnt = socket.size();

    vector<vector<int>> res(cnt, vector<int>(cnt + 1, 0));

    for (int i = 1; i < cnt; i++) res[0][i] = cal_map[socket[0]][i];

    //  res[i][j] put j para before i
    for (int i = 1; i < cnt; i++) {
        int min_limit = i + 1;
        for (int j = min_limit; j <= cnt; j++) {l_sockets
            int last_min_limit = i;
            for (int k = last_min_limit; k <= j; k++) {
                res[i][j] += res[i - 1][k] * cal_map[socket[i]][j - k] % MM;
                res[i][j] %= MM;
            }
        }
    }

    return res[cnt - 1][cnt];
}

int main() {
    char ch;
    while (cin >> ch) {
        if (ch == '(') ori.push_back(1);
        else if (ch == ')') ori.push_back(-1);
    }

    cal_map = vector<vector<int>>(ori.size(), vector<int>(ori.size()));
    for (int i = 0; i < ori.size(); i++) {
        for (int j = 0; j < ori.size(); j++) {
            cal_map[i][j] = cal(i, j);
        }
    }

    r2l();

    l2r();

    int r_way = solve(r_sockets);

    int l_way = solve(l_sockets);

    cout << r_way * l_way % MM << endl;

    return 0;
}