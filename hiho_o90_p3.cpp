#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N, 0);
    vector<int> B(N, 0);
    vector<int> a_remain(N + 1, 0);
    vector<int> b_remain(N + 1, 0);

    int asum = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[i] = a;
        asum += a;
    }
    int aused = 0;
    for (int i = 0; i < N; i++) {
        a_remain[i] = asum - aused;
        aused += A[i];
    }

    int bsum = 0;
    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        B[i] = b;
        bsum += b;
    }
    int bused = 0;
    for (int i = 0; i < N; i++) {
        b_remain[i] = bsum - bused;
        bused += B[i];
    }

    // pick[i, j] = max(A[i] + A_remain[i + 1] + B_remain[j] - pick[i + 1, j], B[j] + A_remain[i] + B_remain[j + 1] - pick[i, j + 1])
    // since pick[i, j] is determined by past infomation in pick, so it could derived by:
    vector<vector<int>> res_tab(N + 1, vector<int>(N + 1, 0));
    for (int i = N; i >= 0; i--) {
        for (int j = N; j >= 0; j--) {
            if (i == N && j  == N) continue;
            if (i == N && j < N) {
                res_tab[i][j] = B[j] + b_remain[j + 1] - res_tab[i][j + 1];
            } else if (j == N && i < N) {
                res_tab[i][j] = A[i] + a_remain[i + 1] - res_tab[i + 1][j];
            } else {
                int pick_a = A[i] + a_remain[i + 1] + b_remain[j] - res_tab[i + 1][j];
                int pick_b = B[j] + a_remain[i] + b_remain[j + 1] - res_tab[i][j + 1];
                res_tab[i][j] = pick_a > pick_b ? pick_a : pick_b;
            }
        }
    }

    cout << res_tab[0][0] << endl;
}