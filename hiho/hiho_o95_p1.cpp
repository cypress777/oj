#include <iostream>
#include <vector>

using namespace std;

int N;
int C;
vector<int> A;
vector<int> B;

int main() {
    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        B.push_back(b);
    }

    long long path = 0;
    int k = 0;
    int left = C;

    while (k < N) {
        if (left - B[k] < 0) {
            path += 2 * A[k - 1];
            left = C;
        } else {
            left -= B[k];
            if (k == N - 1) path += 2 * A[N - 1];
            k++;
        }
    }

    cout << path << endl;
}