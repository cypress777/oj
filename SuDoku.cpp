#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_valid(int n, int id, const vector<int> &mat) {
    int i = id / 9;
    int j = id % 9;
    for (int k = 0; k < 9; k++) {
        if (k != j && mat[i * 9 + k] == n) return false;
        if (k != i && mat[k * 9 + j] == n) return false;
    }
    int idi = i / 3;
    int idj = j / 3;
    for (int di = 0; di < 3; di++) for (int dj = 0; dj < 3; dj++) if ((idi * 3 + di) != i || (idj * 3 + dj) != j) 
        if (mat[(idi * 3 + di) * 9 + idj * 3 + dj] == n) return false;

    return true;
}

bool fill_sudoku(const vector<int> &choices, int id, vector<int> &mat) {
    if (id >= (9 * 9)) return true;

    int i = id / 9;
    int j = id % 9;

    if (mat[i * 9 + j] != 0) {
        return fill_sudoku(choices, id + 1, mat);
    } else {
        for (int k = 1; k <= 9; k++) {
            if (choices[(i * 9 + j) * 10 + k] == 1) {
                if (is_valid(k, id, mat)) {
                    // cout << i << " " << j << " " << k << endl;
                    mat[i * 9 + j] = k;
                    if (fill_sudoku(choices, id + 1, mat)) return true;
                    mat[i * 9 + j] = 0;
                }
            }
        }
        return false;
    }
}

int main() {
    int res = 0;
    for (int i = 0; i < 50; i++) {
        vector<int> choices(9 * 9 * 10, 1);
        vector<int> mat(9 * 9, 0);
        for (int i = 0; i < 9; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < 9; j++) {
                int n = s[j] - '0';
                if (n == 0) continue;
                mat[i * 9 + j] = n;
                for (int k = 1; k <= 9; k++) if (k != n) choices[(i * 9 + j) * 10 + k] = -1;
                for (int k = 0; k < 9; k++) {  // same row
                    if (k != j) choices[(i * 9 + k) * 10 + mat[i * 9 + j]] = -1;  // same row
                    if (k != i) choices[(k * 9 + j) * 10 + mat[i * 9 + j]] = -1;  // same column
                }
                int idi = i / 3;
                int idj = j / 3;
                for (int di = 0; di < 3; di++) for (int dj = 0; dj < 3; dj++) if ((idi * 3 + di) != i || (idj * 3 + dj) != j) 
                    choices[((idi * 3 + di) * 9 + idj * 3 + dj) * 10 + mat[i * 9 + j]] = -1;
            }
        }

        if (!fill_sudoku(choices, 0, mat)) {
            cout << "no answer" << endl;
            break;
        }
        int n = mat[0] * 100 + mat[1] * 10 + mat[2];
        // cout << n << endl;
        res += n;
    }

    cout << res << endl;
    return 0;
}