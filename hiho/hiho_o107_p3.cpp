#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    string S;
    cin >> S;

    vector<int> seg_start;
    vector<int> seg_end;
    char last = S[0];
    int cnt = 1, start = 0;

    for (int i = 1; i < S.size(); i++) {
        if (S[i] == last) {
            cnt++;
            if (i == S.size() - 1 && cnt > 2) {
                seg_start.push_back(start);
                seg_end.push_back(i);
            }
        } else {
            if (cnt > 2) {
                seg_start.push_back(start);
                seg_end.push_back(i - 1);
            }
            cnt = 1;
            last = S[i];
            start = i;
        }
    }

    if (seg_start.empty()) {
        cout << S.size() << endl;
    } else {
        int len = min(int(S.size()), seg_start[0] + 2);
        for (int i = 1; i < seg_start.size(); i++) {
            len = max(len, seg_start[i] - seg_end[i - 1] + 3);
        }
        len = min(int(S.size()), max(len, int (S.size() - seg_end[seg_end.size() - 1] + 1)));
        cout << len << endl;
    }

    return 0;
}

