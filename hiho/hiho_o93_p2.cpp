#include <iostream>
#include <vector>

using namespace std;

int N, M;
int L[1010];
int F[1010];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> F[i];
    }

    unsigned long long cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cnt += min(L[i], F[j]);
        }
    }

    cout << cnt << endl;

    return 0;
}
