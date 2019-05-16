#include <iostream>
#include <vector>

using namespace std;

void gen_prime_tab(int n, vector<int> &tab, vector<int> &is_prime) {
    is_prime = vector<int>(n + 1, true);
    tab = vector<int>();

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) tab.push_back(i);

        for (int p : tab) {
            if (p * i > n) break;
            is_prime[p * i] = false;
            if (i % p == 0) break;
        }
    }
}

int main() {
    vector<int> prime_tab;
    vector<int> is_prime;
    gen_prime_tab(1000000, prime_tab, is_prime);

    int num;
    cin >> num;

    for (int p : prime_tab) {
        if (p * 2 > num) break;
        if (is_prime[num - p]) {
            cout << p << " " << num - p << endl;
            return 0;
        }
    }

    return 0;
}

