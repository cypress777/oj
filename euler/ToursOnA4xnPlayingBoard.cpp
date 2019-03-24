#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> T;
long long NN = 1000000000000L;
//long long NN = 10;
long long MM = 100000000L;

vector<vector<long long>> mult(const vector<vector<long long>> &a, const vector<vector<long long>> &b) {
    vector<vector<long long>> res(a.size(), vector<long long>(b[0].size(), 0));

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < a[0].size(); k++) {
                res[i][j] += (a[i][k] * b[k][j]) % MM;
                res[i][j] %= MM;
            }
        }
    }

    return res;
}

vector<vector<long long>> quick_pow(long long p) {
    vector<vector<long long>> res = {{1, 0, 0, 0, 0, 0, 0, 0},  // -> 0
                                     {0, 1, 0, 0, 0, 0, 0, 0},
                                     {0, 0, 1, 0, 0, 0, 0, 0},
                                     {0, 0, 0, 1, 0, 0, 0, 0},
                                     {0, 0, 0, 0, 1, 0, 0, 0},
                                     {0, 0, 0, 0, 0, 1, 0, 0},
                                     {0, 0, 0, 0, 0, 0, 1, 0},
                                     {0, 0, 0, 0, 0, 0, 0, 1}};
    vector<vector<long long>> base = T;
    while (p > 0) {
        if (p & 1) res = mult(res, base);
        p /= 2;
        base = mult(base, base);
    }
    return res;
}

int main() {
    T = {{0, 0, 1, 1, 1, 0, 1, 1},  // -> 0
         {1, 0, 0, 0, 0, 1, 0, 0},
         {1, 0, 0, 0, 0, 1, 0, 0},
         {1, 0, 0, 0, 0, 1, 0, 0},
         {1, 0, 0, 0, 0, 0, 0, 0},
         {1, 0, 0, 0, 0, 1, 0, 0},
         {0, 0, 1, 0, 0, 0, 1, 0},
         {0, 0, 0, 1, 0, 0, 0, 1}};

    vector<vector<long long>> f0(8, vector<long long>(1, 0));
    f0[0][0] = 1;

    // fn = M * fn-1
    // fn = M^NN * f0

    vector<vector<long long>> trans = quick_pow(NN);
    vector<vector<long long>> res = mult(trans, f0);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 8; i++) cout << res[i][0] << endl;
    cout << "res: " << res[1][0] << endl;

}