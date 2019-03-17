#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int NN = 2000;
int MM = 2019;
// vector<vector<float>> probs;
vector<float> probs;
int n;

int main () {
    cin >> n;
    probs = vector<float>(NN, 0);
    // probs = vector<vector<float>>(NN, vector<float>(MM + 1, 0));
    
    // P[i] = (P[i - 1] + ... P[i - n] + ... P[i - 100]) * 0.01
    probs[n] = 1;
    for (int i = n + 1; i < 2000; i++) {
        for (int j = 1; j <= 100; j++) {
            if (i - j < n) break;
            probs[i] += 0.01 * probs[i - j];
        }
    }

    float res = 0;
    for (int i = 0; i < 2000; i++) {
        if (i + 100 < 2000) continue;
        if (i + 1 > 2019) break;

        res += probs[i] * (min(i + 100, 2019) - max(i + 1, 2000) + 1) / 100.0;
    }

    cout << setiosflags(ios::fixed) << setprecision(1) << (res * 100.0) << endl;

    return 0;
}
