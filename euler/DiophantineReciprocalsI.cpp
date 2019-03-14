#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// N = p1^a1 * p2^a2 * ... pn^an where {pn} are primes
// num of divisions of N would be (a1 + 1) * (a2 + 1) * ... (an + 1)

int N = 10000000;
vector<int> prime_tab;
vector<int> is_prime;

void gen_prime_tab() {
    int count = 0;
    is_prime = vector<int>(N + 1, 1);

    for (int i = 2; i < N; i++) {
        if (is_prime[i] == 1) {
            prime_tab.push_back(i);
            count += 1;
        }

        for (int p : prime_tab) {
            if (p * i > N) break;
            is_prime[p * i] = 0;
            if (i % p == 0) break;
        }
    }
}

int num_of_div(unsigned long long n) {
    int count = 1;
    for (int p : prime_tab)  {
        int pn = 0;
        while (n % p == 0) {
            pn++;
            n /= p;
        }
        count *= (pn + 1);
        if (n <= 1) break;
    }
    return count;
}

int main() {
    gen_prime_tab();

    int count = 0;
    unsigned long long n = 1;
    while (count < 1000) {
        n++;
        count = ceil(num_of_div(n * n) / 2.0f);
    }
    cout << n << endl;
}
