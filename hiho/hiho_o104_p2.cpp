#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string oris;
    cin >> oris;

    int cur = 0;
    string ress;
    while (cur < oris.size()) {
        if (oris[cur] == '0')  { // 0
            ress.push_back('C');

            cur++;
        } else {
            if (oris[cur + 1] == '1') { // 11
                ress.push_back('B');

                cur += 2;
            } else {
                if (oris[cur + 2] == '0') { // 100
                    ress.push_back('D');
                } else { // 101
                    ress.push_back('A');
                }

                cur += 3;
            }
        }
    }

    cout << ress << endl;

    return 0;
}

