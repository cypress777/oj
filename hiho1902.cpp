#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <queue>
#include <ctime>
#include <bitset>
#include <string>
#include <cstdio>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

void bfs(int idx, const vector<vector<int>> &cvt, vector<int> &cnct) {
    vector<int> queue(1, idx);
    vector<int> vst(26, 0);
    int r = 0, f = 0;
    while (r <= f) {
        int to = queue[r];
        for (auto from : cvt[to]) {
            if (vst[from] == 0) {
                vst[from] = 1;
                queue.push_back(from);
                f++;
                cnct[from] = 1;
            }
        }
        r++;
    }
}

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;
    vector<int> alps(26, 0);
    for (auto s : S) {
        alps[s - 'a']++;
    }

    vector<vector<int>> convert(26, vector<int>());
    bool from_h = false;
    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        char from = a[0];
        char to = b[0];
        if (from == to) continue;
        if (from == 'h') from_h = true;
        convert[to - 'a'].push_back(from - 'a');
    }

    vector<int> connection(26, 0);
    bfs('h' - 'a', convert, connection);

    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (connection[i] == 1) cnt += alps[i];
    }
    if (connection['h' - 'a'] == 0 && !from_h) cnt += alps['h' - 'a'];
    cout << cnt << endl;
}