#include <vector>
#include <iostream>
#include <string>

using namespace std;

int N;
vector<string> dict;
string S;

int compare(const string a, const string &b) {
    bool found = false;
    int cura = 0;
    int curb = 0;
    while (cura < a.size() && curb < b.size()) {
        int find = false;
        for (int j = curb; j < b.size(); j++) {
            if (a[cura] == b[j]) {
                find = true;
                cura += 1;
                curb = j + 1;
                if (cura >= a.size()) return true;
                break;
            }
        }
        if (!find) return false;
    }
    return false;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        dict.emplace_back(s);
    }

    cin >> S;

    int min_del = 100000;
    for (int i = 0; i < N; i++) {
        int del = 100000;
        if (compare(dict[i], S)) del = S.size() - dict[i].size();
        min_del = del < min_del ? del : min_del;
    }

    cout << min_del << endl;
    return 0;
}