#include <vector>
#include <iostream>
#include "../src/math_utils.hpp"

using namespace std;

vector<int> prime_tab;
vector<vector<int>> count;
vector<vector<long long>> sum;
int digits = 10;
long long number = 10000000000L;

int main() {
    gen_prime_tab<int>(100000, prime_tab);
    cout << prime_tab.size() << endl;

    count = vector<vector<int>>(10, vector<int>(digits + 1, 0));
    sum = vector<vector<long long>>(10, vector<long long>(digits + 1, 0));

    for (int i = number / 10; i < number; i++) {
        if (!isPrime<int>(i, prime_tab)) continue;

        long long p = i;

        if (p < number / 10) continue;

        vector<int> cnt(10, 0);
        while (p > 0) {
            cnt[p % 10]++;
            p /= 10;
        }

        for (int j = 0; j < 10; j++) {
            if (cnt[j] < 2) continue;
            count[j][cnt[j]]++;
            sum[j][cnt[j]] += i;
        }
    }

    long long res = 0;
    for (int i = 0; i < 10; i++) {
        int max_cnt = 0;
        int max_j = 0;
        for (int j = 2; j <= digits; j++) {
            if (count[i][j] != 0) {
                max_cnt = count[i][j];
                max_j = j;
            }
        }
        res += sum[i][max_j];
    }
    cout << res << endl;
}
