#include <vector>
#include <iostream>

using namespace std;

vector<long long> a;
vector<long long> b;
long long tot, ave, N;

int main() {
    cin >> N;

    a = vector<long long>(N);
    b = vector<long long>(N);
    tot = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
        tot += a[i];
        tot += b[i];
    }
    ave = tot / (2 * N);

    long long time = 0;
    for (int i = 0; i < N; i++) {
        if (i == N - 1) {
            time += ave - min(a[i], b[i]);
        } else {
            long long out_a, out_b, in_a, in_b, inter;
            if (a[i] >= ave && b[i] >= ave) {
                out_a = a[i] - ave;
                out_b = b[i] - ave;
                time += (out_a + out_b);

                a[i + 1] += out_a;
                b[i + 1] += out_b;
            } else if (a[i] <= ave && b[i] <= ave) {
                in_a = ave - a[i];
                in_b = ave - b[i];
                time += (in_a + in_b);

                a[i + 1] -= in_a;
                b[i + 1] -= in_b;
            } else if (min(a[i], b[i]) <= ave && max(a[i], b[i]) >= ave) {
                if (a[i] >= b[i]) {
                    inter = min(a[i] - ave, ave - b[i]);
                    out_a = (a[i] - inter) - ave;
                    in_b = ave - (b[i] + inter);
                    time += (inter + out_a + in_b);

                    a[i + 1] += out_a;
                    b[i + 1] -= in_b;
                } else {
                    inter = min(b[i] - ave, ave - a[i]);
                    in_a = ave - (a[i] + inter);
                    out_b = (b[i] - inter) - ave;
                    time += (inter + in_a + out_b);

                    a[i + 1] -= in_a;
                    b[i + 1] += out_b;
                }
            }
        }
    }
    cout << time << endl;

    return 0;
}

