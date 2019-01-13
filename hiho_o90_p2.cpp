#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    unordered_map<int, int> seats_taken;

    long long rem = 3 * N;
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        int row = 0, col_idx = 0, col = 0;
        for (int j = 0; j < s.size() - 1; j++) {
            row *= 10;
            row += s[j] - '0';
        }
        row -= 1;
        col = s[s.size() - 1] - 'A';
        if (col <= 'C' - 'A') {
            col_idx = 0;
        } else if (col <= 'G' - 'A') {
            col_idx = 1;
        } else if (col <= 'K' - 'A') {
            col_idx = 2;
        }
        if ((col_idx == 0 || col_idx == 2) && seats_taken.find(row * N + col_idx) == seats_taken.end()) {
            seats_taken[row * N + col_idx] = 1;
            rem -= 1;
        } else if (col_idx == 1 && seats_taken.find(row * N + col_idx) != seats_taken.end() && seats_taken[row * N + col_idx] == 0) {
            seats_taken[row * N + col_idx] = 1;
            rem -= 1;
        } else if (col_idx == 1 && seats_taken.find(row * N + col_idx) == seats_taken.end()) {
            if (col == 'D' - 'A' || col == 'G' - 'A') {
                seats_taken[row * N + col_idx] = 0;
            } else {
                seats_taken[row * N + col_idx] = 1;
                rem -= 1;
            }
        }
    }

    cout << rem << endl;
}