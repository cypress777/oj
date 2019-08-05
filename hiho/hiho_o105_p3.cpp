#include <vector>
#include <iostream>
#include <string>

using namespace std;

int MinRepresentation(const string &s) {
    int i = 0, j = 1, k = 0, n = s.size();

    while (i < n && j < n && k < n) {
        if (s[(i + k) % n] == s[(j + k) % n]) {
            k++;
        } else {
            s[(i + k) % n] > s[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
            if (i == j) i++;
            k = 0;
        }
    }

    return min(i, j);
}

int main() {
    string s;
    cin >> s;

    int n = s.size();

    int id = MinRepresentation(s);

    string ss = "";
    for (int i = 0; i < n; i++) {
        ss.push_back(s[(id + i) % n]);
    }

    cout << ss << endl;

    return 0;
}

