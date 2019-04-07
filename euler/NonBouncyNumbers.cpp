#include <iostream>
#include <vector>

using namespace std;

int N = 10;

vector<vector<long long>> result;

long long cal(int start, int digit) {
//    cout << start << " " << digit << endl;
    if (result[start][digit] != -1) return result[start][digit];
    if (digit == 0) {
        result[start][digit] = 0;
        return 0;
    }
    if (digit == 1) {
        result[start][digit] = 10 - start;
        return 10 - start;
    }

    long long res = 0;
    for (int i = start; i < 10; i++) {
        res += cal(i, digit - 1);
    }

    result[start][digit] = res;
    return res;
}

int main() {
    long long count = 0;

    result = vector<vector<long long>>(10, vector<long long>(N + 1, -1));

    for (int i = 1; i <= N; i++) {
        count += cal(1, i);
    }

    for (int i = 1; i <= N; i++) {
        count += cal(0, i);
    }

    count = count - N * 10;

    cout << count << endl;

    return 0;
}

