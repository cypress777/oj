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
    int last_r_cnt = 0;
    int r_cnt = 0;

    for (int i = ori.size() - 1; i >= 0; i++) {
        val += ori[i];
        if (ori[i] == 1) r_cnt++;
        if (val > 0) {
            val = 0;
            r_sockets.push_back(r_cnt - last_r_cnt);
            last_r_cnt = r_cnt;
        }
        i--;
    }
}

void l2r() {
    int val = 0;
    int last_l_cnt = 0;
    int l_cnt = 0;

    for (int i = 0; i < ori.size(); i++) {
        val += ori[i];
        if (ori[i] == -1)  l_cnt++;
        if (val < 0) {
            val = 0;
            l_sockets.push_back(l_cnt - last_l_cnt);
            last_l_cnt = l_cnt;
        }
        i++;
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

    res[0][1] = cal_map[socket[cnt - 1]][1];
    res[0][0] = 1;

    for (int i = 1; i < cnt; i++) {
        int limit = i + 1;
        for (int j = 0; j <= limit; j++) {
            for (int k = 0; k <= j ; k++) {
                if (j - k > limit - 1) continue;
                res[i][j] += res[i - 1][j - k] * cal_map[socket[cnt - 1 - i]][k] % MM;
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