#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N;
vector<vector<int>> bricks;
unordered_map<int, int> count;

int main() {
    cin >> N;
    bricks = vector<vector<int>>(N, vector<int>());
    int max_width = 0;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        int width = 0;
        for (int j = 0; j < n; j++) {
            int b;
            cin >> b;
            if (b == 0) continue;
            bricks[i].push_back(b);
            width += b;
        }
        if (width > max_width) max_width = width;
    }

//    cout << max_width << endl;

    int max_slot = 0;
    for (int i = 0; i < N; i++) {
        int slot = 0;
        for (int j = 0; j < bricks[i].size(); j++) {
            slot += bricks[i][j];
            if (slot == max_width) continue;
            if (count.find(slot) == count.end()) count[slot] = 1;
            else count[slot]++;
            if (count[slot] > max_slot) max_slot = count[slot];
        }
    }

    cout << N - max_slot << endl;

    return 0;
}

