#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> alphbet(26, vector<int>{});
    string A, B;
    cin >> A;
    cin >> B;
    for (int i = 0; i < A.size(); i++) {
        alphbet[A[i] - 'a'].push_back(i);
    }
    // for (int i = 0; i < 26; i++) {
    //     if (alphbet[i].size() == 0) continue;
    //     cout << i << ": ";
    //     for (int j = 0; j < alphbet[i].size(); j++)
    //         cout << alphbet[i][j] << " ";
    //     cout << endl;
    // }

    int expand_time = 1;

    int r = -1;
    for (int i = 0; i < B.size(); i++) {
        int num = alphbet[B[i] - 'a'].size();
        if (num == 0) {
            cout << -1 << endl;
            return 0;
        } else {
            if (alphbet[B[i] - 'a'][num - 1] <= r) {
                expand_time++;
                r = alphbet[B[i] - 'a'][0];
                continue;
            }
            for (int idx : alphbet[B[i] - 'a']) {
                if (idx > r) {
                    r = idx;
                    break;
                }
            }
        }
        // cout << B[i] << " " << r << " " << expand_time << endl;
    }

    cout << expand_time << endl;
    return 0;
}