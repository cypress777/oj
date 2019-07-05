#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int MM = 1000000;
//int MM = 100;

int main() {
    long long cnt = 0;

    for (int i = 1; i <= MM; i++) {
        for (int m = 1; m < sqrt(i); m++) {
            if (i % m != 0) continue;

            int n = i / m;

            if ((m + n) % 2 != 0) continue;

            int a = (m + n) / 2;
            int b = (n - m) / 2;

            if ((a - b) % 2 == 0) {
                cnt++;
//                cout << cnt << " " << i << " " << a << " " << b << endl;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}

