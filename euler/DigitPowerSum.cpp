#include <iostream>
#include <algorithm>

using namespace std;

long long MM;

vector<long long> res;

bool valid(int p, long long n) {
    if (n < 10) return false;

    int sum = 0;
    while (n > 0) {
        sum += (n % 10);
        if (sum > p) return false;
        n /= 10;
    }

    return (sum == p);
}

int main () {
    MM = 1000000000000000000L;

    int cnt = 0;
    for (int i = 2; i < 200; i++) {

        long long n = i;
        int power = 1;

        while (n < MM / i) {
            if (valid(i, n)) {
                res.push_back(n);
            }

            n *= i;
            power++;
        }
    }

    sort(res.begin(), res.end());

    cout << res.size() << endl;

    for (long long r : res) cout << r << " ";
    cout << endl;
    cout << res[29] << endl;
}

