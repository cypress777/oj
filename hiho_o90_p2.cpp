#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// |ABC| |DEFG| |HJK|
// | 0 | |  1 | | 2 |

int main() {
    long long N, M;
    cin >> N >> M;

    unordered_map<long long, int> seats_taken;

    long long rem = 3 * N;
    // cout << rem << endl;
    for (long long i = 0; i < M; i++) {
        string s;
        cin >> s;
        long long row = 0, col_idx = 0, col = 0;
        for (long long j = 0; j < s.size() - 1; j++) {
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
        // cout << row << " " << col_idx << endl;
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
    return 0;
}