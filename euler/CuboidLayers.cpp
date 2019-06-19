#include <iostream>
#include <vector>

using namespace std;

long long cal(int x, int y, int z, int n) {
    return (x * y + y * z + x * z) * 2 + 4 * (n - 1) * (x + y + z + n - 2);
}

int main() {
    int mm = 20000;
    int ll = 10000;
    int nn = 1000;
    int want = 1000;

    vector<int> cnt(mm + 1, 0);

    for (int x = 1; x <= ll; x++) {
        if (cal(x, x, x, 1) > mm) break;

        for (int y = x; y <= ll; y++) {
            if (cal(x, y, y, 1) > mm) break;

            for (int z = y; z <= ll; z++) {
                if (cal(x, y, z, 1) > mm) break;

                for (int n = 1; n <= nn; n++) {
                    if (cal(x, y, z, n) > mm) break;

                    cnt[cal(x, y, z, n)]++;
                }
            }
        }
    }

    for (int i = 0; i <= mm; i++) {
        if (cnt[i] == want) {
            cout << i << " " << cnt[i] << endl;
//            break;
        }
    }
    cout << cnt[18522] << endl;

    return 0;
}
