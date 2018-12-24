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

int bfs(int idx, const vector<vector<int>> &cvts, vector<int> &alps, vector<int> &flgs) {
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (flgs[i] != -1) {
            flgs[i] = -1;
            if (cvts[i][idx] == 1) {
                cnt += alps[i] + bfs(i, cvts, alps, flgs);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;
    vector<int> alps(26, 0);
    for (auto s : S) {
        alps[s - 'a'] += 1;
    }

    vector<vector<int>> convert(26, vector<int>(26, 0));
    for (int i = 0; i < N; i++) {
        string ss;
        cin >> ss;
        char from = ss[0];
        char to = ss[2];
        cout << from << ' ' << to;
        convert[from][to] = 1;
    }

    vector<int> flgs(26, 0);
    flgs['h' - 'a'] = -1;
    int res = alps['h' - 'a'] + bfs('h' - 'a', convert, alps, flgs);
}