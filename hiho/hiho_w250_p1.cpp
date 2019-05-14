#include <iostream>
#include <vector>

using namespace std;

vector<int> ori;
vector<int> r_sockets;
vector<int> l_sockets;
long long MM = 1000000007;

void r2l() {
    int val = 0;
    int r_cnt = 0;

    for (int i = ori.size() - 1; i >= 0; i--) {
        val += ori[i];
        if (ori[i] == 1) {
            if (val > 0) {
                r_cnt++;
                val = 0;
            }
            r_sockets.push_back(r_cnt);
        }
    }
//    cout << "------- r: " << endl;
//    for (auto r : r_sockets) cout << r << " ";
//    cout << endl;
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
//    cout << "------- l: " << endl;
//    for (auto l : l_sockets) cout << l << " ";
//    cout << endl;
}

long long solve(vector<int> socket) {
    if (socket.empty()) return 1;
    int cnt = socket[socket.size() - 1];

    vector<vector<long long>> res(socket.size(), vector<long long>(cnt + 1, 0));

    for (int i = socket[0]; i <= cnt; i++) res[0][i] = 1;



    for (int i = 1; i < socket.size(); i++) {
        for (int k = socket[i - 1]; k <= socket[i]; k++) {
            res[i][socket[i]] += res[i - 1][k];
            res[i][socket[i]] %= MM;
        }
        for (int j = socket[i] + 1; j <= cnt; j++) {
            res[i][j] = res[i][j - 1] + res[i - 1][j];
            res[i][j] %= MM;
        }
    }

    return res[socket.size() - 1][cnt];
}

int main() {
    char ch;
    while (cin >> ch) {
        if (ch == '(') ori.push_back(1);
        else if (ch == ')') ori.push_back(-1);
    }
//
//    cout << "------- ori: " << endl;
//    for (auto o : ori) cout << o << " ";
//    cout << endl;

    r2l();

    l2r();

    int r_cnt = 0, l_cnt = 0;
    long long r_way = 1, l_way = 1;

    r_way = solve(r_sockets);
    if (!r_sockets.empty()) r_cnt = r_sockets[r_sockets.size() - 1];

    l_way = solve(l_sockets);
    if (!l_sockets.empty()) l_cnt = l_sockets[l_sockets.size() - 1];

    cout << (r_cnt + l_cnt) % MM << " " << r_way * l_way % MM << endl;

    return 0;
}