#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string decode(const string &ss) {
    vector<string> elements;

    int cur = 1;
    while (cur < ss.size() - 1) {
        vector<char> stack(ss.size());
        int p = 0;
        stack[p] = ss[cur];

        string ele;
        ele.push_back(ss[cur]);

        cur++;

        while (cur < ss.size() - 1) {
            ele.push_back(ss[cur]);

            if (stack[p] == '[' && ss[cur] == ']' || stack[p] == '{' && ss[cur] == '}') {
                p--;
            } else {
                p++;
                stack[p] = ss[cur];
            }

            cur++;

            if (p == -1) break;
        }

        ele = decode(ele);

        elements.push_back(ele);
    }

    string decoded;

    if (ss[0] == '{') {
        sort(elements.begin(), elements.end());

        for (int i = 0; i < elements.size(); i++)  {
            if (i > 0 && elements[i] == elements[i - 1]) continue;
            decoded += elements[i];
        }
    } else {
        for (int i = 0; i < elements.size(); i++) {
            decoded += elements[i];
        }
    }

    decoded = ss[0] + decoded + ss[ss.size() - 1];

    return decoded;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        string a, b;
        cin >> a >> b;

        a = decode(a);
        b = decode(b);

        if (a == b) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

