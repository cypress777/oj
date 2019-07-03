#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_pairs(const vector<int> &a, const vector<int> &b) {
    return false;
}

bool is_3332(const vector<int> &a, const vector<int> &b) {
    return false;
}

bool is_valid(const vector<vector<int>> &hand) {
    vector<int> id_a = {0, 0, 1};
    vector<int> id_b = {1, 2, 2};

    for (int k = 0; k < 3; k++) {
        if (is_pairs(hand[id_a[k]], hand[id_b[k]])) return true;
        if (is_3332(hand[id_a[k]], hand[id_b[k]]))) return true;
    }

    return false;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> hand(3, vector<int>(10, 0));
    for (int i = 0; i < 14; i++) {
        string s;
        cin >> s;

        hand[s[0] - 'a'][s[1] - '0']++;
    }

    vector<string> stack(N);
    for (int i = 0; i < N; i++) {
        cin >> stack[i];
    }

    int step = -1;
    if (is_valid(hand)) {
        step = 0;
    } else {
        for (int i = 0; i < N; i++) {
            hand[stack[i][0] - 'a'][stack[i][1] - '0']++;
            if (is_valid(hand)) {
                step = i + 1;
                break;
            }
        }
    }

    cout << step << endl;

    return 0;
}

