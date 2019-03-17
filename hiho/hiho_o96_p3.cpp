#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> sta;
vector<int> ed;
vector<int> ids;
vector<int> cnts;

int main() {
    cin >> N >> M;

    sta = vector<int>(N + 1, 0);
    ed = vector<int>(N + 1, 0);
    cnts = vector<int>(N + 1, 0);
    ids = vector<int>(M, -1);

    for (int i = 0; i < M; i++) {
        cin >> ids[i];
        cnts[ids[i]]++;

        if (i > 0 && ids[i] != ids[i - 1]) {
            sta[min(ids[i], ids[i - 1])]++;
            ed[max(ids[i], ids[i - 1])]++;
        }
    }

    int cnt = 0;
    for (int i = 0; i <= N; i++) {
        cnt -= ed[i];
        cnts[i] += cnt;
        cnt += sta[i];
        if (i < N) cout << cnts[i] << " ";
        if (i == N) cout << cnts[i] << endl;
    }

    return 0;
}