#include <iostream>
#include "../src/math_utils.hpp"

using namespace std;

long long MM = 1000000000;
long long N = 100;
vector<long long> ptab;

void calc(int pos, long long val, int &cnt) {
    for (int i = pos + 1; i < ptab.size(); i++) {
        long long mult = ptab[i];
        int t = 1;

        while (mult * val <= MM)  {
            cnt++;

//            cout << cnt << " " << ptab[i] << " " << t << " " << " " << mult * val << endl;

            calc(i, mult * val, cnt);

            mult *= ptab[i];
        }
    }
}

int main() {
    gen_prime_tab(N + 1, ptab);

    int cnt = 1;
    calc(-1, 1, cnt);

    cout << cnt << endl;

    return 0;
}