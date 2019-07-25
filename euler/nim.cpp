#include <iostream>

using namespace std;

int EXP = 30;

int main() {
    int MM = 1U << EXP;
    cout << MM << endl;

    int cnt = 0;
    for (int n = 1; n <= MM; n++) {
        int a = n, b = 2 * n, c = 3 * n;
        if ((a ^ b ^ c) == 0) cnt++;
    }

    cout << cnt << endl;
}