#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int N;
int NN;
int M;
long long MM;

vector<vector<long long>> A;
vector<vector<long long>> AA;
vector<vector<long long>> B;
vector<vector<long long>> BB;
vector<long long> dec_mod;

int main() {
    NN = 5;
    N = NN / 2;
    M = N * 9;
//    MM = pow(3, 15);
    MM = 100000;

    A = vector<vector<long long>>(N + 10, vector<long long>(M + 10, 0));
    AA = vector<vector<long long>>(N + 10, vector<long long>(M + 10, 0));
    B = vector<vector<long long>>(N + 10, vector<long long>(M + 10, 0));
    BB = vector<vector<long long>>(N + 10, vector<long long>(M + 10, 0));

    long long base = 1;
    for (int i = 0; i <= N + 10; i++) {
        base = base % MM;
        dec_mod.push_back(base);
        base *= 10;
    }

    A[0][0] = 1;
    for (int i = 0; i <= 9; i++) A[1][i] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = 0; k <= 9; k++) {
                if (j - k <= 0) break;
                A[i][j] = (A[i][j] + A[i - 1][j - k]) % MM;
            }
            cout << i << " " << j << " " << A[i][j] << endl;
        }
    }

    AA[0][0] = 1;
    for (int i = 0; i <= 9; i++) AA[1][i] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            AA[i][j] = (AA[i][j] + AA[i - 1][j] + A[i][j]) % MM;
        }
    }

    for (int i = 0; i <= 9; i++) B[1][i] = i;
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k <= 9; k++) {
                if (j - k <= 0) break;
                B[i][j] = (B[i][j] + B[i - 1][j - k] * 10 + k * A[i - 1][j - k]) % MM;
            }
        }
    }

    for (int i = 0; i <= 9; i++) BB[1][i] = i;
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            BB[i][j] = (BB[i][j] + BB[i - 1][j] + B[i][j]) % MM;
        }
    }


    long long res = 0;
    for (int i = 1; i <= NN; i++) {
        int n = i / 2;
        int m = n * 9;
        for (int j = 0; j <= m; j++) {
            if (j == 0 && i != 1) continue;
            long long a = B[n][j] * AA[n][j] % MM;
            long long b = BB[n][j] * A[n][j] % MM;
            if (i % 2 == 1) {
                long long c = (A[n][j] * AA[n][j] * 45) % MM;
                res = (res + (a * dec_mod[n + 1] + b) * 10 + c * dec_mod[n]) % MM;
            } else if (i % 2 == 0) {
                res = (res + a * dec_mod[n] + b) % MM;
            }
        }
    }

    cout << (long long)res << endl;
}
