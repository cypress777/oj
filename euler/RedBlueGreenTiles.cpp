#include <iostream>
#include <vector>

using namespace std;

long long cal(int n, int m) {
    vector<long long> result(n + 1, 0);
    result[m] = 1;

    for (int i = m + 1; i <= n; i++) {
        for (int j = 0; j <= i - m; j++) {
            result[i] += result[i - (j + m)] + 1;
        }
    }

    return result[n];
}

int main() {
    int N = 50;

    long long res = cal(N, 2);
    res += cal(N, 3);
    res += cal(N, 4);

    cout << res << endl;

    return 0;
}