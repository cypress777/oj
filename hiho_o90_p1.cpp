#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b) {
    return a > b;
}

void show_vec(vector<int> a) {
    for (auto aa : a) cout << aa << "  " << endl;
    cout << endl;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> pplt(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> pplt[i];
    }

    for (int i = 0; i < M; i++) {
        sort(pplt.begin(), pplt.end(), comp);
        for (int j = 0; j < N; j++) {
            pplt[j] += K * 100;
        }
        // show_vec(pplt);
        pplt[0] /= 2;
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += pplt[i];
    }
    cout << sum << endl;
}