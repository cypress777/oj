#include <iostream>
#include <vector>

using namespace std;

long long MM = 1000000;
vector<int> cnt;

int main() {
    cnt = vector<int>(MM + 1, 0);

    for (long long a = 1; a <= 2 * MM; a++) {
        for (long long b = (long long)(a / 4) + 1; b < a; b++) {

            long long val = (4 * b - a) * a;
            if (val > MM) break;

            cnt[val]++;
        }
    }

    cout << cnt[1155] << endl;
    cout << cnt[27] << endl;
    cout << cnt[MM] << endl;

    int tot = 0;
    for (int i = 0; i < cnt.size(); i++) {
        if (cnt[i] == 10) {
            tot++;
        }
    }

    cout << tot << endl;

    return 0;
}