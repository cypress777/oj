#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_pairs(const vector<int> &a, const vector<int> &b) {
    int pairs = 0;

    for (int n : a) if (n >= 2) pairs++;
    for (int n : b) if (n >= 2) pairs++;

    return pairs >= 7;
}

bool is_432(const vector<int> &a, const vector<int> &b, int step, int cnt) {
    if (step == 4) {
        if (cnt < 4) return false;
        for (int n : a) if (n >= 2) return true;
        for (int n : b) if (n >= 2) return true;
        return false;
    }

    for (int i = 1; i <= 9; i++) {
        if (a[i] >= 3) {
            auto new_a = a;
            new_a[i] -= 3;
            if (is_432(new_a, b, step + 1, cnt + 1)) return true;
        }

        if (b[i] >= 3) {
            auto new_b = b;
            new_b[i] -= 3;

            if (is_432(a, new_b, step + 1, cnt + 1)) return true;
        }
    }

    for (int i = 1; i <= 7; i++) {
        if (a[i] > 0 && a[i + 1] > 0 && a[i + 2] > 0) {
            auto new_a = a;
            new_a[i]--;
            new_a[i + 1]--;
            new_a[i + 2]--;
            if (is_432(new_a, b, step + 1, cnt + 1)) return true;
        }

        if (b[i] > 0 && b[i + 1] > 0 && b[i + 2] > 0) {
            auto new_b = b;
            new_b[i]--;
            new_b[i + 1]--;
            new_b[i + 2]--;

            if (is_432(a, new_b, step + 1, cnt + 1)) return true;
        }
    }

    return false;
}

bool is_valid(const vector<vector<int>> &hand) {
    vector<int> id_a = {0, 0, 1};
    vector<int> id_b = {1, 2, 2};

    for (int k = 0; k < 3; k++) {
        if (is_pairs(hand[id_a[k]], hand[id_b[k]])) return true;
        if (is_432(hand[id_a[k]], hand[id_b[k]], 0, 0)) return true;
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

