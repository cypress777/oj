#include <iostream>
#include <vector>

using namespace std;

vector<int> A;
vector<int> B;
vector<int> a_remain;
vector<int> b_remain;
vector<vector<int>> res_tab;

int pick(int i, int j) {
    // cout << i << " " << j << endl;
    if (i >= A.size() && j >= B.size()) return 0;

    if (i >= A.size() && j == B.size() - 1) {
        return B[j];
    } else if (i >= A.size() && j < B.size() - 1) {
        int b_rem = j + 1 < B.size() ? b_remain[j  + 1] : 0;
        return B[j] + b_rem - pick(i, j + 1);
    }
    if (j >= B.size() && i == A.size() - 1) {
        return A[i];
    } else if (j >= B.size() && i < A.size() - 1) {
        int a_rem = i + 1 < A.size() ? a_remain[i  + 1] : 0;
        return A[i] + a_rem - pick(i + 1, j);
    }

    if (i == A.size() - 1 && j == B.size() - 1) {
        res_tab[i][j] = A[i] > B[j] ? A[i] : B[j];
    }

    if (res_tab[i][j] != -1) {
        // cout << res_tab[i][j] << endl;
        return res_tab[i][j];
    }

    int from_a, from_b;
    if (i + 1 < A.size())
        from_a = A[i] + a_remain[i + 1] + b_remain[j] - pick(i + 1, j); 
    else
        from_a = A[i] + b_remain[j] - pick(i + 1, j);

    if (j + 1 < B.size())
        from_b = B[j] + a_remain[i] + b_remain[j + 1] - pick(i, j + 1);
    else
        from_b = B[j] + a_remain[i] - pick(i, j + 1);

    res_tab[i][j] = from_a > from_b ? from_a : from_b;
    // cout << res_tab[i][j] << endl;
    return res_tab[i][j];
}

int main() {
    int N;
    cin >> N;

    int asum = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
        asum += a;
    }
    int aused = 0;
    for (int i = 0; i < N; i++) {
        a_remain.push_back(asum - aused);
        aused += A[i];
    }

    int bsum = 0;
    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        B.push_back(b);
        bsum += b;
    }
    int bused = 0;
    for (int i = 0; i < N; i++) {
        b_remain.push_back(bsum - bused);
        bused += B[i];
    }

    for (int i = 0; i < N; i++) {
        res_tab.push_back(vector<int>());
        for (int j = 0; j < N; j++) {
            res_tab[i].push_back(-1);
        }
    }
    int res = pick(0, 0);
    cout << res << endl;
}