#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int MM = 100000;

unordered_map<int, int> row;
unordered_map<int, int> col;
unordered_map<int, int> dia;
unordered_map<int, int> rdia;

vector<int> combines;

int main() {
    combines = vector<int>(MM + 1, 0);

    for (int i = 2; i <= MM; i++) {
        combines[i] = i * (i  - 1) / 2;
    }

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;

        if (row.find(r) == row.end()) {
            row[r] = 1;
        } else {
            row[r]++;
        }

        if (col.find(c) == col.end()) {
            col[c] = 1;
        } else {
            col[c]++;
        }

        if (dia.find(c - r) == dia.end()) {
            dia[c - r] = 1;
        } else {
            dia[c - r]++;
        }

        if (rdia.find(c + r) == rdia.end()) {
            rdia[c + r] = 1;
        } else {
            rdia[c + r]++;
        }
    }

    long long tot = 0;
    for (auto r : row) {
        tot += combines[r.second];
    }

    for (auto c : col) {
        tot += combines[c.second];
    }

    for (auto d : dia) {
        tot += combines[d.second];
    }

    for (auto rd : rdia) {
        tot += combines[rd.second];
    }

    cout << tot << endl;

    return 0;
}

