#include <iostream>
#include <vector>

using namespace std;

int NN = 100;

int main() {
    vector<int> vals = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 25};
    vector<int> ids;
    vector<int> w;
    int id = 0;
    for (int i = 0; i <= vals.size(); i++) {
        w.push_back(vals[i]);
        id++;
        w.push_back(vals[i] * 2);
        ids.push_back(id);
        id++;
        if (vals[i] != 25) w.push_back(vals[i] * 3), id++;
    }

    // f(j, i) = f(j - 1, i) + f(j, i - w[j])
    vector<int> res(NN + 1, -1);
    res[0] = 1;
    res[1] = 1;
    for (int j = 1; j < w.size(); j++) {
        for (int i = w[j]; i <= NN; i++) {
            res[i] += res[i] + res[i - w[j]];
        }
    }

    return 0;
}