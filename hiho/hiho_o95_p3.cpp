#include <iostream>
#include <vector>

using namespace std;

int N;
long long L;
long long max_B;
vector<int> A;
vector<int> B;
long long total_B;

bool valid(long long vol) {
    long long path = 0;
    int k = 0;
    long long left = vol;

    while (k < N) {
        if (left - B[k] < 0) {
            path += 2 * A[k - 1];
            left = vol;
        } else {
            left -= B[k];
            if (k == N - 1) path += 2 * A[N - 1];
            k++;
        }
        if (path > L) return false;
    }
    return true;
}

int main() {
    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.emplace_back(a);
    }

    total_B = 0;
    max_B = 0;
    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        B.emplace_back(b);
        total_B += b;
        if (b > max_B) max_B = b;
    }


    long long con_min = max_B;
    long long con_max = total_B;
    long long con_mid = (con_max + con_min) / 2;

    while (con_min + 1 < con_max) {
        if (valid(con_mid)) {
            con_max = con_mid;
        } else {
            con_min = con_mid + 1;
        }
        con_mid = (con_max + con_min) / 2;
    }

    if (valid(con_min)) {
        cout << con_min << endl;
    } else {
        cout << con_max << endl;
    }

    return 0;
}