#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;

int main() {
    cin >> N;
    long long cnt = 0;
    int last_h = 0;
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        cnt += max(0, h - last_h);
        last_h = h;
    }

    cout << cnt << endl;
    return 0;
}
