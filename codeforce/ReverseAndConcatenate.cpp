#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        if (k == 0) {
            cout << 1 << endl;
            continue;
        }

        bool sym = true;
        for (int j = 0; j < n / 2; j++) {
            if (s[j] != s[n - 1 - j]) {
                sym = false;
                break;
            }
        }

        if (sym) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }

    return 0;
}