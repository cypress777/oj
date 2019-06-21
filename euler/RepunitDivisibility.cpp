#include <iostream>

using namespace std;

int A(int n) {
    if (n % 2 == 0 || n % 5 == 0) return 0;

    int x = 1;
    int k = 1;

    while (x != 0) {
        x = (x * 10 + 1) % n;
        k++;
    }
//    cout << n << " " << k << endl;
    return k;
}
int main() {
    int limit = 1000001;
    int n = 2;

    while (A(n) < limit) {
        n++;
    }

    cout << n << endl;
}

