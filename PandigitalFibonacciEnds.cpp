#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

unsigned long long MM = static_cast<unsigned long long>(1e18);
unsigned long long mm = static_cast<unsigned long long>(1e9);

unsigned long long sum_head(unsigned long long h1, unsigned long long h2) {
    unsigned long long sumh;
    if (h2 < h1) {
        sumh = (h1 / 10 + h2);
    } else {
        sumh = h1 + h2;
    }
    return sumh > MM ? sumh / 10 : sumh;
}

unsigned long long valid(unsigned long long n) {
    if (n / 1e8 < 1) return false;

    while (n / static_cast<unsigned long long>(1e9) > 0) n /= 10;

    string ns = to_string(n);
    sort(ns.begin(), ns.end());
    if (ns == "123456789") {
        return true;
    } else {
        return false;
    }
}

int main() {
    unsigned long long head1, head2, tail1, tail2;
    head1 = 1;
    head2 = 1;
    tail1 = 1;
    tail2 = 1;
    int n = 2;
    while (!valid(head2) || !valid(tail2)) {
        unsigned long long tailtmp = (tail1 + tail2) % mm;
        tail1 = tail2;
        tail2 = tailtmp;

        unsigned long long headtmp = sum_head(head1, head2);
        head1 = head2;
        head2 = headtmp;

        n++;
    }

    cout << n << endl;

    return 0;
}