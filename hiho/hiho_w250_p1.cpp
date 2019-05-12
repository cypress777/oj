#include <iostream>
#include <vector>

using namespace std;

vector<int> ori;
vector<int> r_sockets;
vector<int> l_sockets;
int MM = 1000000007;

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

int solve(vector<int> socket) {
    int miss = socket.size();
    vector<vector<int>> res(socket.size(), vector<int>(miss + 1, 0));
    for (int i = ; i <= cnt; i++) res[0][i] = 1;
    for (int i = 1; i < socket.size(); i++) {
        for (int j = 0; j <= cnt; j++) {
            for (int k = 0; k <= socket[i]; k++) {
                res[i][j] += res[i - 1][j - k];
            }
        }
    }
}

int main() {
    char ch;
    while (cin >> ch) {
        if (ch == '(') ori.push_back(1);
        else if (ch == ')') ori.push_back(-1);
    }

    r2l();

    l2r();

    int r_way = solve(r_sockets);

    int l_way = solve(l_sockets);

    cout << r_way * l_way % MM << endl;

    return 0;
}