#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, x;
        long long y;
        cin >> n >> x >> y;

        int count = 0; 
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            if (num % 2 == 1) count++;
        }

        // cout << count << " " << x << " " << y << endl;

        if ((count % 2 == 0 && x % 2 == y % 2) || (count % 2 == 1 && x % 2 != y % 2)) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }

    return 0;
}