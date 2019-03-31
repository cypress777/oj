#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int N, K;
long long MM = 1e18;
vector<int> array;

bool dividable(long long n) {
    int part = 0;
    long long s = 0;

    for (int i = 0; i < N; i++) {
        s += array[i];
        if (s >= n) {
            part++;
            if (part >= K) return true;
            s = 0;
        }
    }
    return false;
}

int main() {
    cin >> N >> K;

    array = vector<int>(N, 0);

    long long min_res = MM;
    long long max_res = 0;
    for (int i = 0; i < N; i++) {
        cin >> array[i];
        if (array[i] < min_res) min_res = array[i];
        max_res += array[i];
    }

    long long mid_res = (min_res + max_res) / 2;
    while (min_res < max_res - 1) {
        if (dividable(mid_res)) min_res = mid_res;
        else max_res = mid_res;
        mid_res = (min_res + max_res) / 2;
    }
    if (dividable(max_res)) cout << max_res << endl;
    else cout << min_res << endl;
    return 0;
}
