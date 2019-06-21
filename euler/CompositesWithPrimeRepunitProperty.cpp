#include <iostream>
#include "../src/math_utils.hpp"

using namespace std;

int A(int n) {
    int x = 1;
    int k = 1;

    while (x != 0) {
        x = (x * 10 + 1) % n;
        k++;
    }
//    cout << n << " " << k << endl;
    return k;
}

int main() {
    int mm = 1000000;

    vector<int> p_tab;
    gen_prime_tab(mm, p_tab);
    cout << p_tab.size() << endl;

    int nn = 25;

    int cnt = 0;
    int n = 6;
    int tot = 0;
    while (cnt < nn) {
        n++;

        if (n % 2 == 0 || n % 5 == 0 || isPrime(n, p_tab)) {
            continue;
        }

        int k = A(n);
//        cout << n << " " << k << endl;
        if ((n - 1) % k == 0) {
            cnt++;
            tot += n;
            cout << cnt << " " << n << " " << k << endl;
        }
    }

    cout << tot << endl;

    return 0;
}

