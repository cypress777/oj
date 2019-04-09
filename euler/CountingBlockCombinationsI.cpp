#include <vector>
#include <iostream>

using namespace std;

int N;

vector<long long> red_res;
vector<long long> gray_res;

long long cal(int remain, int red) {
    long long res = 0;

    if (red == 1) {
        if (red_res[remain] != -1) {
            return red_res[remain];
        }
        if (remain == 3) {
            red_res[remain] = 1;
            return 1;
        }

        for (int i = 3; i <= remain; i++) {
            if (remain - i >= 1) res += cal(remain - i, -1);
            if (remain - i == 0) res++;
        }
        red_res[remain] = res;
    } else if (red == -1) {
        if (gray_res[remain] != -1) {
            return gray_res[remain];
        }
        if (remain <= 3) {
            gray_res[remain] = 1;
            return  1;
        }

        for (int i = 1; i <= remain; i++) {
            if (remain - i >= 3) res += cal(remain - i, 1);
            if (remain - i == 0) res++;
        }
        gray_res[remain] = res;
    }

    return res;
}

int main() {
    N = 50;

    red_res = vector<long long>(N + 1, -1);
    gray_res = vector<long long>(N + 1, -1);

    long long res = cal(N, 1) + cal(N, -1);

    cout << res << endl;

    return 0;
}
