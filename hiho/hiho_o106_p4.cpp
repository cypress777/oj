#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void gen_prime_tab(T n, std::vector<T> &prime_tab) {
    int count = 0;
    auto is_prime = std::vector<bool>(n + 1, true);
    prime_tab = std::vector<T>{};

    for (T i = 2; i < n; i++) {
        if (is_prime[i]) {
            prime_tab.push_back(i);
            count += 1;
        }

        for (T p : prime_tab) {
            if (p * i > n) break;
            is_prime[p * i] = false;
            if (i % p == 0) break;
        }
    }
}

void get_factors(vector<int> &ft, const vector<int> &ptab) {
    int nn = n;
    for (auto p : ptab) {
        if (nn % p == 0) ft.push_back(p);

        while (nn % p == 0) {
            nn /= p;
        }

        if (nn == 0) break;
    }
}

int calc(const vector<int> &ft, int num, int mult, int rem) {

}

int main() {
    int n;
    cin >> n;

    int k = (n + 3) / 2;

    vector<int> ptab;
    gen_prime_tab(n, ptab);

    vector<int> ft;
    get_factors(ft, ptab);

    int cnt = 0;
    int sign = 1;
    int fsize = ft.size();
    for (int i = 0; i < fsize; i++) {
//        std::cout << ft[i] << std::endl;
        cnt += sign * calc(ft, i, )
    }

    return 0;
}

