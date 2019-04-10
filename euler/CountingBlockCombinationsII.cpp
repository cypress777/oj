#include <vector>
#include <iostream>

using namespace std;

int N;
int M;

vector<long long> red_res;
vector<long long> gray_res;

long long cal(int remain, int red) {
    long long res = 0;

    if (red == 1) {
        if (red_res[remain] != -1) {
            return red_res[remain];
        }
        if (remain == M) {
            red_res[remain] = 1;
            return 1;
        }

        for (int i = M; i <= remain; i++) {
            if (remain - i > 0) res += cal(remain - i, -1);
            if (remain - i == 0) res++;
        }
        red_res[remain] = res;
    } else if (red == -1) {
        if (gray_res[remain] != -1) {
            return gray_res[remain];
        }
        if (remain <= M) {
            gray_res[remain] = 1;
            return  1;
        }

        for (int i = 1; i <= remain; i++) {
            if (remain - i >= M) res += cal(remain - i, 1);
            if (remain - i == 0) res++;
        }
        gray_res[remain] = res;
    }

    return res;
}

int main() {
    N = 1000;
    M = 50;

    red_res = vector<long long>(N + 1, -1);
    gray_res = vector<long long>(N + 1, -1);

    for (int i = 50; i < 1000; i++) {
        long long res = cal(i, 1) + cal(i, -1);
        if (res > 1000000) {
            cout << i << " " << res << endl;
            break;
        }
    }

    return 0;
}
