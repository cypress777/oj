#include <vector>
#include <iostream>

using namespace std;

int n;
vector<long long> s;
vector<long long> a;

int lowbit(int n) {
    return n & ~(n - 1);
}

long long get(int n) {
    long long res = 0;
    while (n > 0) {
        res += s[n];
        n -= lowbit(n);
    }
    return res;
}

void add(int n, long long x) {
    while (n < s.size()) {
        s[n] += x;
        n += lowbit(n);
    }
}

int main() {
    cin >> n;

    s = vector<long long>(n + 1, 0);
    a = vector<long long>(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long result = 0;

    for (int i = n; i > 0; i--) {
        result += get(a[i]) * i;
        add(a[i], n - i + 1);
    }

    cout << result << endl;

    return 0;
}
