#include <vector>
#include <iostream>
#include <cmath>
#include "../src/math_utils.hpp"

using namespace std;

double MM;
int N = 13;
int thres = 4000000;
vector<int> prime_tab;

void dfs(double pre_val, int pre_count, const vector<int> &pows) {
    if (pows.size() >= N) return;

    int base = prime_tab[pows.size()];
    int max_num = pows.empty() ? thres : pows[pows.size() - 1];

    for (int i = 1; i <= max_num; i++) {
        vector<int> new_pows = pows;
        new_pows.push_back(i);

        double val = pre_val * pow(base, i);
        if (val > MM) return;

        int count = pre_count * (i + 1);
        if (count % 2 == 1 && (count / 2 + 1) >= thres) {
            cout << "MM: " << (unsigned long long)sqrt(MM) << " val: " << (unsigned long long)sqrt(val) << " count: " << count << endl;
            MM = val;
            for (int ps : new_pows) cout << ps << " ";
            cout << endl;
            return;
        }

        dfs(val, count, new_pows);
    }
}

int main() {
    // 4 ^ 11 > 4000000
    gen_prime_tab(1000, prime_tab);
    for (int i = 0; i <= N; i++) cout << prime_tab[i] << " ";
    cout << endl;

    MM = 1;
    for (int i = 0; i <= N; i++) MM *= (prime_tab[i] * prime_tab[i] * prime_tab[i]);
    cout << MM << endl;

    dfs(1, 1, {});
    cout << (unsigned long long)sqrt(MM) << endl;

    return 0;
}