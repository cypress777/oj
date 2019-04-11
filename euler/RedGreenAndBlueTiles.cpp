#include <vector>
#include <iostream>

using namespace std;

long long cal(int n, const vector<int> &m) {
    vector<long long> result(n + 1, 0);
    result[m[0]] = 1;

    for (int i = m[0] + 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int mm : m) {
                if (i - (j + mm) >= 0) result[i] += result[i - (j + mm)] + 1;
            }
        }
    }

    return result[n];
}

int main() {
    long long res = cal(50, {2, 3, 4}) + 1;

    cout << res << endl;

    return 0;
}