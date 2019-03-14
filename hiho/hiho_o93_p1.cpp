#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> A, B;

int main() {
    cin >> N;
    unsigned long long total = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
        total += a;
    }
    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        B.push_back(b);
    }

    unsigned long long even_cnt = 0;
    unsigned long long odd_cnt = 0;
    unsigned long long idx = 0;
    for (int i = 0; i < N; i++) {
        if (B[i] == 1) {
            if (idx % 2 == 0) {
                even_cnt += A[i] / 2 + A[i] % 2;
                odd_cnt += A[i] / 2;
            } else {
                even_cnt += A[i] / 2;
                odd_cnt += A[i] / 2 + A[i] % 2;
            }
        }
        idx += A[i];
    }

    unsigned long long even_ones = (total / 2 + total % 2) - even_cnt + odd_cnt;
    unsigned long long odd_ones = even_cnt + total / 2 - odd_cnt;

    unsigned long long min = even_ones > odd_ones ? odd_ones : even_ones;

    cout << min << endl;

    return 0;
}