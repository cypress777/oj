#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int MM = 1000000;

int main () {
    vector<int> count(MM + 1, 0);

    for (int a = 3; a < MM; a++) {
        for (int b = a - 2; b > 0; b-=2)  {
            int t = a * a - b * b;
            if (t > MM) break;

            count[t]++;
        }
    }

    int tot = 0;
    for (int i = 0; i < count.size(); i++) {
        if (count[i] >= 1 && count[i] <= 10) tot++;
    }

    cout << tot << endl;

    return 0;
}

