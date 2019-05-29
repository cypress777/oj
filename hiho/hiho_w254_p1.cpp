#include <iostream>
#include <cmath>
#include <memory.h>

using namespace std;

int A[3000000][2];

inline void update(int i, int j) {
    if (j > A[i][0]) {
        A[i][1] = A[i][0];
        A[i][0] = j;
    } else if (j > A[i][1]) {
        A[i][1] = j;
    }
}

int main() {
    int MM = pow(2, 20);

    int N;
    scanf("%d", &N);

    for (int k = 0; k < N; k++) {
        int M;
        scanf("%d", &M);

        for (int i = 0; i < MM * 2; i++) {
            A[i][0] = 0;
            A[i][1] = 0;
        }

        for (int i = 0; i < M; i++) {
            int a;
            scanf("%d", &a);
            if (A[a][0] == 0) A[a][0] = a;
            else A[a][1] = a;
        }

        long long max_res = 0;
        for (int j = 19; j >= 0; j--) {
            for (int i = (1 << 20) - 1; i >= 0; i--) {
                if (i & (1 << j)) {
                    int ii = i - (1 << j);
                    update(ii, A[i][0]);
                    update(ii, A[i][1]);
                }
            }
        }

        for (int i = 1; i < MM; i++) {
            long long res = (long long)(A[i][0]) * A[i][1] * i;
            if (res > max_res) max_res = res;
        }

        cout << max_res << endl;
    }
}

