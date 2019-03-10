#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MM = 1e6;
int N;
vector<int> A;
vector<int> s;

int main() {
    cin >> N;

    s = vector<int>(MM + 1, 0);

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        s[a] = 1;
        A.emplace_back(a);
    }

    for (int i = 1; i < s.size(); i++) s[i] += s[i - 1];

    int max_num = 0;
    for (int i = 0; i < A.size(); i++) {
        int num = s[A[i]] - s[max(0, A[i] - N)];
        if (max_num < num) max_num = num;
    }

    cout << N - max_num << endl;
    return 0;
}