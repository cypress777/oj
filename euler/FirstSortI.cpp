#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int MM = 30;

int main() {
    vector<int> steps(MM + 1, 0);
    for (int i = 2; i <= MM; i++) {
        steps[i] = steps[i - 1] * 2 + 1;
    }

    vector<double> res(MM + 1, 0);
    res[1] = 0;

    for (int i = 2; i <= MM; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == i) continue;

            res[i] += steps[j] + 1;
        }
        res[i] /= double(i);
        res[i] += res[i - 1];
    }

    cout << setprecision(15) << res[MM] << endl;

    return 0;
}


