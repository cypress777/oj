#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool showed(long long b, long long c, const vector<long long> &bs, const vector<long long> &cs) {
    for (int i = 0; i < bs.size(); i++) {
        if (bs[i] == b && cs[i] == c) return true;
    }
    return false;
}

int main() {
    long long tot = 0;
    for (long long a = 3; a <= 1000; a++) {
        long long res = 0;
        long long aa = a * a;
        long long b = a - 1;
        long long c = (a + 1) % aa;
        vector<long long> bs;
        vector<long long> cs;

        while (!showed(b, c, bs, cs)) {
//            cout << b % aa << " " << c % aa << " " << (b + c) % aa << endl;
            bs.push_back(b);
            cs.push_back(c);
            res = max((b + c) % aa, res);
            b *= (a - 1);
            b %= aa;
            c *= (a + 1);
            c %= aa;
        }
        tot += res;
    }

    cout << tot << endl;

    return 0;
}
