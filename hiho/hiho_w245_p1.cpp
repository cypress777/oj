#include <iostream>
#include <vector>

using namespace std;

int N;
int len = 1001;

vector<int> f;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

//int get_f(int n) {
//    if (f[n] == -1) return n;
//    f[n] == get_f(f[n]);
//    return f[n];
//}

int get_f(int n) {
    int nn = n;
    while (f[nn] != -1) {
        nn = f[nn];
    }
    while (f[n] != -1) {
        int tmpn = n;
        n = f[n];
        f[tmpn] = nn;
    }
    return nn;
}

int main() {
    cin >> N;

    f = vector<int>(1e6, -2);

    int num = 0, area = 0, peri = 0;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        if (x < 0 || x >= 1000 || y < 0 || y >= 1000) continue;
        int id = 1000 * x + y;

        if (f[id] != -2) continue;

        f[id] = -1;
        area += 1;

        vector<int> kinds{};
        int kin = 0;
        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            int iid = 1000 * xx + yy;

            if (xx < 0 || xx >= 1000 || yy < 0 || yy >= 1000) continue;
            if (f[iid] == -2) continue;
            kin++;

            int fiid = get_f(iid);

            bool has = false;
            for (int s : kinds) {
                if (fiid == s) {
                    has = true;
                    break;
                }
            }

            if (!has) kinds.push_back(fiid);
        }

        for (int s : kinds) f[s] = id;

        peri += 4 - 2 * kin;
        num -= (kinds.size() - 1);

        cout << num << " " << area << " " << peri << endl;
    }

    return 0;
}

