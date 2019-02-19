#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int MM = 1000000;
vector<int> nexts;

int get_next(int n) {
    if (nexts[n] != -1) return nexts[n];
    int res = 1;
    int sqn = int(sqrt(n));
    for (int i = 2; i <= sqn; i++) {
        if (n % i == 0) res += i, res += n / i;
        if (res > MM) return 10 * MM;
    }
    return res;
}

bool in_chain(int n, vector<int> chain) {
    for (int nn : chain) if (n == nn) return true;
    return false;
}

int main() {
    nexts = vector<int>(MM + 1, -1);

    int max_len = 0;
    int max_n = 0;
    for (int i = 3; i <= MM; i++) {
        int ii = get_next(i);
        int len = 1;
        vector<int> chain;
        bool valid = true;

        while(ii != i) {
            if (ii > MM) {  // exceed limit
                valid = false;
                break;
            } else if (in_chain(ii, chain)) {  // in chain
                valid = false;
                break;
            }
            len += 1;
            chain.emplace_back(ii);

            int nii = get_next(ii);
            nexts[ii] = nii;
            ii = nii;
        }

        if (valid) {
            if (len > max_len) max_len = len, max_n = i;
        }

        if (i % 1000 == 0) cout << i << " " << max_n << " " << max_len << endl;
    }

    cout << max_len << endl;

    return 0;
}