#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int N;
int MM = 1000001;

unordered_set<int> points;

int main() {
    cin >> N;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        int p = y * MM + x;
        int pr = y * MM + x + 1;
        int pl = y * MM + x - 1;
        if (points.find(p) == points.end() && points.find(pr) ==  points.end() && points.find(pl) ==  points.end()) {
            points.insert(p);
            cnt++;
        }
    }

    cout << cnt << endl;
}
