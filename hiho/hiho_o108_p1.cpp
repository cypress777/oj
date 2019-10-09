#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;

    vector<int> A(N);
    vector<int> B(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    auto p_next = upper_bound(A.begin(), A.end(), C);

    int idx = p_next - A.begin();

    if (p_next == A.end()) {
        cout << B[idx - 1] << endl;
        return 0;
    }

    cout << B[idx - 1] << " " << A[idx] - C << " " << B[idx] << endl;

    return 0;
}

