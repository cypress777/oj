#include <iostream>
#include <vector>
#include "../src/math_utils.hpp"

using namespace std;

int MM = 1000000;
//int MM = 100;

int main() {
    vector<int> ptab;
    gen_prime_tab(MM + 100, ptab);

    vector<vector<int>> mult_tab(10, vector<int>(10, -1));

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            mult_tab[i][i * j % 10] = j;
        }
    }

    long long res = 0;

    for (int i = 0; i < ptab.size(); i++) {
        int p1 = ptab[i];
        int p2 = ptab[i + 1];
        if (ptab[i] < 5 || ptab[i] > MM) continue;

        int d = 1;
        while (d <= p1) d *= 10;

        long long n = p2;
        int r = p2;

        if (p2 % 10 == 5) {
            while (r != p1) {
                n += p2;
                r = n % d;
            }
        } else {
            long long k = mult_tab[p2 % 10][p1 % 10];
            while (r != p1) {
                n = p2 * k;
                r = n % d;
                k += 10;
            }
        }

//        cout << p1 << " " << p2 << " " << n << endl;
        res += n;
    }

    cout << res << endl;

    return 0;
}

