#include <iostream>
#include <vector>
#include <cmath>
#include "../src/math_utils.hpp"

using namespace std;

int main() {
    long long mm = 100000000000;
    long long nn = 2000;

    vector<long long> prime_tab;
    gen_prime_tab((long long)(sqrt(mm) + 1), prime_tab);

    cout << prime_tab.size() << endl;

    long long cnt = 0;
    long long r = 1;
    long long id = 2;
    while (cnt < nn && id < mm) {
        id = r * (r - 1) * 3 + 2;
        if (isPrime(12 * r + 5, prime_tab) && isPrime(6 * r - 1, prime_tab) && isPrime(6 * r + 1, prime_tab)) {
            cnt++;
        }
        if (cnt == nn) break;

        id = r * (r + 1) * 3 + 1;
        if (isPrime(6 * r + 5, prime_tab) && isPrime(12 * r - 7, prime_tab) && isPrime(6 * r - 1, prime_tab)) {
            cnt++;
        }
        if (cnt == nn) break;
        r++;
    }

    cout << cnt << " " << id << endl;

    return 0;
}

