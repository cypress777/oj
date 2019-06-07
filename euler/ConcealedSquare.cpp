#include <iostream>
#include <vector>

using namespace std;

int main() {
    for (long long i = 0; i < 1000000; i++) {
        for (long long j = 10; j <= 14; j++) {
            vector<long long> tail = {30, 70};
            for (long long t : tail) {
                long long n = (j * 1000000 + i) * 100 + t;
                long long nn = n * n;
//                cout << n << " " << nn << endl;

                int pos = 0;
                bool valid = true;
                while (nn > 0) {
                    if (pos % 2 == 0) {
                        if (nn % 10 != (10 - pos / 2) % 10) {
                            valid = false;
                            break;
                        }
                    }
                    nn /= 10;
                    pos++;
                }

                if (valid) {
                    cout << n << " " << n * n << endl;
                }
            }
        }
    }
    return 0;
}

