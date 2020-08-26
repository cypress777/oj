#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include "../src/math_utils.hpp"

using namespace std;

vector<int> ptab;
unordered_set<int> pset;
int MM = 100;

void get_p(int tot, int cnt, int n, vector<vector<int>> &P) {
    if (n >= ptab.size()) return;

    if (tot > MM) return;

    for (int i = n; i < ptab.size(); i++) {
        int val = tot + ptab[i];
        if (val > MM) break;

        P[val].push_back(cnt + 1);

        get_p(val, cnt + 1, i, P);
    }
}

int P(int n) {
    if (n <= 3) return 1;

    int res = n / 2 - 2;
    if (n % 2 == 0) return res + 1;

    if (pset.find(n) != pset.end()) res++;
    if (pset.find(n - 2) != pset.end()) res++;
    return res;
}

int main() {
    vector<long long> fib(45);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= 44; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    unordered_set<int> fib_set;
    for (int i = 3; i <= 44; i++) fib_set.insert(fib[i]);

    MM = (fib[fib.size() - 1]) + 1;
    cout << "max fib: " << (fib[fib.size() - 1]) << endl;

    gen_prime_tab(MM + 1, ptab);

    for (auto p : ptab) pset.insert(p);

//    vector<vector<int>> P(MM + 1, vector<int>());
//
//    get_p(0, 0, 0, P);
//
//    for (int i = 0; i < P.size(); i++) {
//        sort(P[i].begin(), P[i].end());
//
//        int val = 0;
//        cout <<"---- " << i << ": ";
//        for (int j = 0; j < P[i].size(); j++) {
//            if (j > 0 && P[i][j] == P[i][j - 1]) continue;
//            cout << P[i][j] << " ";
//
//            val++;
//        }
//        cout << endl;
//
//        cout << i << ": "  << val << endl;
//    }
//
//    cout << S(73) << endl;

    long long val = 0;
    long long tot = 0;
    for (int i = 2; i <= MM; i++) {
        val += P(i);
        if (i == 10 || i == 100 || i == 1000) cout << i << " " << val << endl;
        if (fib_set.find(i) != fib_set.end()) tot += val;
    }

    cout << tot << endl;
    return 0;
}

