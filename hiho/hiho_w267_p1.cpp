#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, L;
    cin >> N >> M >> L;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    vector<long long> B(M);
    for (int i = 0; i < M; i++) cin >> B[i];
    sort(B.begin(), B.end());

    vector<long long> C(L);
    for (int i = 0; i < L; i++) cin >> C[i];
    sort(C.begin(), C.end());

    long long res = 1000000000;

    for (int i = 0; i < N; i++) {
        int a = A[i];
        vector<long long> b, c;

        size_t id = upper_bound(B.begin(), B.end(), a) - B.begin();
        if (id >= 0 && id < B.size()) b.push_back(B[id]);

        id--;
        if (id >= 0 && id < B.size()) b.push_back(B[id]);

        if (b.empty()) b.push_back(B[B.size() - 1]);

        id = upper_bound(C.begin(), C.end(), a) - C.begin();
        if (id >= 0 && id < C.size()) c.push_back(C[id]);

        id--;
        if (id >= 0 && id < C.size()) c.push_back(C[id]);

        if (c.empty()) c.push_back(C[C.size() - 1]);

        for (int m = 0; m < b.size(); m++) {
            for (int n = 0; n < c.size(); n++) {
                res = min(res, abs(a - b[m]) + abs(a - c[n]) + abs(b[m] - c[n]));
            }
        }
    }

    cout << res << endl;

    return 0;
}
