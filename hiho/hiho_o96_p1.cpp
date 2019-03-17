#include <iostream>
#include <vector>

using namespace std;

int N;
int MM = 100;
vector<int> map;

int main() {
    cin >> N;

    map = vector<int>(1, -1);
    char n;
    while (cin >> n) {
        if (n == '*') map.push_back(1);
        else map.push_back(0);
    }

    int row = 0;
    bool have_top = false;
    for (int i = 1; i < map.size(); i++) {
        if (i > row * row) {
            have_top = false;
            row++;
        }

        if (map[i] == 1) {
            cout << '*';
            have_top = !have_top;
            if (i == row * row) cout << endl;
            continue;
        }

        int top, left, right, bottom;

        int cnt = 0;

        if (have_top) {
            top = i - (row - 1) * 2;
            if (top > 0) cnt += map[top];
            have_top = false;
        } else {
            bottom = i + row * 2;
            if (bottom <= N * N) cnt += map[bottom];
            have_top = true;
        }

        left = i - 1;
        if (left >= (row - 1) * (row - 1) + 1) cnt += map[left];

        right = i + 1;
        if (right <= row * row) cnt += map[right];

        cout << cnt;
        if (i == row * row) cout << endl;
    }
}