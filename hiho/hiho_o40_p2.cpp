#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    vector<vector<int>> chain(10, vector<int>());

    for (int i = 0; i < 10; i++) {
        if (i == 0 || i == 5) {
            chain[i].push_back(i);
            continue;
        } else {
            int mult = i;
            chain[i].push_back(mult);

            int n = (i + 8) % 10;

            while (n != 0 && n != 5) {
                mult = n * mult % 10;
                chain[i].push_back(mult);
                n = (n + 8) % 10;
            }

            chain[i].push_back(n);
        }
    }

//    for (int i = 0; i < 10; i++) {
//        cout << "---- " << endl;
//        for (int j = 0; j < chain[i].size(); j++) {
//            cout << chain[i][j] << " ";
//        }
//        cout << endl;
//    }

    for (int i = 0; i < T; i++) {
        long long x, k;
        cin >> x >> k;

        if (k == 1) {
            cout << x << endl;
        } else if (x % 2 != k % 2) {
            cout << -1 << endl;
        } else {
            bool has = false;

            for (int n = 0; n < chain[x % 10].size(); n++) {
                if (chain[x % 10][n] == k) {
                    long long y = x - 2 * n - 2;
                    if (y > 0) {
                        cout << y << endl;
                        has = true;
                    }
                    break;
                }
            }
            if (!has) cout << -1 << endl;
        }
    }

    return 0;
}

