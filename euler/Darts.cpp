#include <iostream>
#include <vector>

using namespace std;

int NN = 100;

int main() {
    vector<int> vals = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 25};
    vector<int> ids{};
    vector<int> w{};
    for (int i = 0; i < vals.size(); i++) {
        w.push_back(vals[i]);
        w.push_back(vals[i] * 2);
        ids.push_back(w.size() - 1);
        if (vals[i] != 25) w.push_back(vals[i] * 3);
    }
    w.push_back(0);

    vector<int> f(NN, 0);
    for (int i = 0; i < w.size(); i++) {
        for (int j = i; j < w.size(); j++) {
            if (w[i] + w[j] < 100) f[w[i] + w[j]]++;
        }
    }

    long long res = 0; 
    for (int id : ids) {
        for (int i = 0; i < NN; i++) {
            if (i + w[id] < NN) res += f[i];
        }
    }

    cout << res << endl;

    return 0;
}