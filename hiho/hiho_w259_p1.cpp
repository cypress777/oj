#include <iostream>
#include <vector>
#include <string>

using namespace std;

void convert() {
    string s;
    cin >> s;

    string ns;
    bool l2u = false;
    for (int i = 0; i < s.size(); i++) {
        if (l2u) {
            ns.push_back(s[i] - 'a' + 'A');
            l2u = false;
        } else if (!l2u && s[i] >= 'a' && s[i] <= 'z') {
            ns.push_back(s[i]);
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            ns.push_back('_');
            ns.push_back(s[i] - 'A' + 'a');
        } else if (s[i] == '_') {
            l2u = true;
        }
    }

    cout << ns << endl;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        convert();
    }
}
