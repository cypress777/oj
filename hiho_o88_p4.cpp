#include <iostream>
#include <vector>
using namespace std;

int N, K;
int mm = 1000000007;

int main() {
    cin >> N >> K;
    vector<int> A(N, -1);;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<long long>> S(N, vector<long long>(K + 1, 0));
    for (int k = 1; k < K + 1; k++) {
        S[0][k] = 1;
    }

    for (int n = 1; n < N; n++) {
        for (int k = 1; k < K + 1; k++) {
            S[n][k] = 0;
//            cout << n << " " << k << " " << A[n] << " " << A[n - 1];
            if (A[n] > A[n - 1]) {
                for (int i = 1; i < k; i++) {
                    S[n][k] += S[n - 1][i];
                }
            } else if (A[n] < A[n - 1]) {
                for (int i = k + 1; i < K + 1; i++) {
                    S[n][k] += S[n - 1][i];
                }
            } else if (A[n] == A[n - 1]) {
                S[n][k] = S[n - 1][k];
            }
            S[n][k] %= mm;
//            cout << " " << S[n][k] << endl;
        }
    }

    long long res = 0;
    for (int i = 1; i < K + 1; i++) {
        res += S[N - 1][i];
    }
    res %= mm;
    cout << res << endl;
    return 0;
}