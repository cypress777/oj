#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long N, Q;
    cin >> N >> Q;

    long long k = ceil(log2(N / (2.0 * Q)));
    if (k < 0) k = 0;

    cout << (k * Q  + ceil(N / pow(2.0, k))) << endl;

    return 0;
}
