#include <vector>
#include <iostream>

using namespace std;

long long MOD = 1000000007;

vector<vector<long long>> matrix_mult(const vector<vector<long long>> &mat_a,
                                      const vector<vector<long long>> &mat_b) {
    int row_a = mat_a.size(), col_a = mat_a[0].size();
    int row_b = mat_b.size(), col_b = mat_b[0].size();

    vector<vector<long long>> result(row_a, vector<long long>(row_b, 0));

    for (int i = 0; i < row_a; i++) {
        for (int j = 0; j < row_b; j++) {
            long long val = 0;
            for (int k = 0; k < col_a; k++) {
                val = (val + mat_a[i][k] * mat_b[j][k] % MOD) % MOD;
            }

            result[i][j] = val;
        }
    }

    return result;
}

vector<vector<long long>>
matrix_pow(const vector<vector<long long>> &matrix, int power) {
    int row = matrix.size(), col = matrix[0].size();

    vector<vector<long long>> result(row, vector<long long>(col, 0));
    for (int i = 0; i < row; i++) result[i][i] = 1;

    auto base = matrix;

    while (power > 0) {
        if (power % 2 == 1) {
            result = matrix_mult(base, result);
        }

        base = matrix_mult(base, base);
        power /= 2;
    }

    return result;
}

int main() {
    int N, x, y;

    cin >> N >> x >> y;

    vector<vector<long long>> adj_mat(64, vector<long long>(64, 0));

    vector<int> dx = {1, -1, 1, -1, 2, -2, 2, -2};
    vector<int> dy = {2, 2, -2, -2, 1, 1, -1, -1};

    for (int i = 0; i < 64; i++) {
        int xi = i / 8, yi = i % 8;

        for (int k = 0; k < 8; k++) {
            int xj = xi + dx[k], yj = yi + dy[k], j = xj * 8 + yj;

            if (xj < 0 || xj >= 8 || yj < 0 || yj >= 8) continue;

            adj_mat[i][j] = 1;
            adj_mat[j][i] = 1;
        }
    }

    vector<vector<long long>> a = {{1, 2, 3},
                                   {4, 5, 6},
                                   {7, 8, 9}};
    vector<vector<long long>> b = {{1, 0, 0},
                                   {0, 1, 0},
                                   {0, 0, 1}};
    vector<vector<long long>> c = {{1, 0, 0}};

    auto d = matrix_mult(a, c);
    cout << d.size() << " " << d[0].size() << endl;

    for (int i = 0; i < d.size(); i++) {
        for (int j = 0; j < d[0].size(); j++) {
            cout << d[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;

    vector<vector<long long>> fin_mat = matrix_pow(adj_mat, N);

    vector<vector<long long>> init(1, vector<long long>(64, 0));
    init[0][x * 8 + y] = 1;

    vector<vector<long long>> result = matrix_mult(fin_mat, init);

    long long tot = 0;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            tot = (tot + result[i][j]) % MOD;
        }
    }

    cout << tot << endl;

    return 0;
}

