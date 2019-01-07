#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int No = N / 2 + N % 2;
    int Ne = N / 2;
    int flag = N % 2;

    vector<int> factorials(N + 1, 1);
    vector<int> loop_len(N + 1, -1);

    int mul = 1;
    for (int i = 1; i <= N; i++) {
        mul *= i;
        factorials[i] = mul;
    }

    int Noo = No, Nee = Ne;
    for (int i = 1; i <= N; i++) {
        Noo -= i % 2;
        Nee -= (i + 1) % 2;
        loop_len[i] = factorials[Noo] * factorials[Nee]
    }

    vector<int> loop_idx(N + 1, 0);
    int i = 0;
    while (K > 0) {
        loop_idx[i] = K / loop_len[i];
        K %= loop_len[i];
        i++;
    }

    vector<int> vst(N + 1, -1);
    vector<int> res(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        int kk = 0;
        for (int j = 1; j <= N; j++) {
            if (vst[j] == -1 && (i == 1 || (res[i - 1] + j) % 2 == 1)) {
                vst[j] = 1;
                if (kk == loop_idx[i]) {
                    res[i] = j;
                    break;
                }
                kk++;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (i != N) {
            cout << res[i] << " ";
        } else {
            cout << res[i] << endl;
        }
    }
}