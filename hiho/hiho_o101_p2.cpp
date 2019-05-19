#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M, MM;
vector<vector<int>> durations;
vector<long long> res;

int main() {
    cin >> N;

    M = 100;
    MM = 1000000;

    durations = vector<vector<int>>(MM + 1, vector<int>());

    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        durations[s].push_back(e);
    }

    res = vector<long long>(MM + 1, 0);
    for (int s = MM; s >= 0; s--) {
        if (s + 1 <= MM) res[s] = res[s + 1];
        if (!durations[s].empty()) {
            for (int e : durations[s]) {
                long long next = e + 1 > MM ? 0 : res[e + 1];
                res[s] = max(res[s], (e - s + 1) * M + next);
            }
        }
    }

    cout << res[0] << endl;

    return 0;
}