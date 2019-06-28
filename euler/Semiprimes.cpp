#include <iostream>
#include "../src/math_utils.hpp"

using namespace std;

long long MM = 100000000;

int main() {
    vector<long long> prime_tab;
    gen_prime_tab(MM, prime_tab);

    int cnt = 0;

    for (int i = 0; i < prime_tab.size(); i++) {
        for (int j = i; j < prime_tab.size(); j++) {
            if (prime_tab[i] * prime_tab[j] <= MM) {
                cnt++;
            } else {
                break;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}

