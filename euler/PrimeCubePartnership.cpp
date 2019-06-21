#include <iostream>
#include <cmath>
#include "../src/math_utils.hpp"

using namespace std;

int main() {
    int mm = 1000000;

    vector<int> tab;
    gen_prime_tab(mm, tab);

    int cnt = 0;
    for (int p : tab) {
        for (long long a = 1; 3 * a * a + 3 * a + 1 <= p; a++) {
            long long n = a * a * a;
            long long np = n + p;
            bool cube = false;
            for (long long b = floor(cbrt(np)) - 1; b <= floor(cbrt(np)) + 1; b++) {
                long long b3 = b * b * b;
                if (b3 == np) {
                    cube = true;
                    cnt++;
                    break;
                } else if (b3 > np) {
                    break;
                }
            }
            if (cube) break;
        }
    }
    cout << cnt << endl;

    return 0;
}

