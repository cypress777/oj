#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> ys;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ys.emplace_back(y);
    }

    sort(ys.begin(), ys.end());

    int middle = ys[ys.size() / 2];
    long long dist = 0;
    for (int y : ys) dist += abs(y - middle);

    cout << dist << endl;
    return 0;
}

