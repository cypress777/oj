#include <iostream>
#include <vector>

using namespace std;

int MM = 100000;
int N;
vector<int> cnt(2 * MM + 1, 0);

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        cnt[a] += 1;
    }

    int res = 0;
    for (int i = 0; i < cnt.size(); i++) {
        if (cnt[i]) {
            res += min(cnt[i], cnt[i * 2]);
            cnt[i * 2] = max(0, cnt[i * 2] - cnt[i]);
        }
    }

    cout << res << endl;

    return 0;
}
