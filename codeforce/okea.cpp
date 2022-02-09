#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        if (n == 1 && k > 1) {
            cout << "NO" << endl;
            continue;
        }

        if (k == 1) {
            cout << "YES" << endl;
            for (int j = 1; j <= n; j++) cout << j << endl;
            continue;
        }

        if (n % 2 == 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int j = 0; j < n / 2; j++) {
                cout << 2 * k * j + 1;
                for (int l = 1; l < k; l++) {
                    cout << " " << 2 * k * j + 1 + 2 * l;
                }
                cout << endl;

                cout << 2 * k * j + 2;
                for (int l = 1; l < k; l++) {
                    cout << " " << 2 * k * j + 2 + 2 * l;
                }
                cout << endl;
            }
        }
    }

    return 0;
}