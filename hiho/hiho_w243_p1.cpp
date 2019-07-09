#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_map<char, int> cnt;
    cnt['h'] = 0;
    cnt['i'] = 0;
    cnt['o'] = 0;

    vector<int> ids;
    int min_len = -1;

    int i = 0;
    while (i < s.size()) {
        if (s[i] == 'h' || s[i] == 'i' || s[i] == 'o') {
            cnt[s[i]]++;
            ids.push_back(i);

//            cout << "----" << endl;
//            cout << i << " " << s[i] << endl;
//
//            for (int id : ids) cout << id << " ";
//            cout << endl;
//
//            for (auto c : cnt) cout << c.first << " " << c.second << ", ";
//            cout << endl;

            if (cnt['h'] == 2 && cnt['i'] == 1 && cnt['o'] == 1) {
                int len = i - ids[0] + 1;

                if (min_len == -1 || len < min_len) min_len = len;

                cnt[s[ids[0]]]--;
                ids = {ids[1], ids[2], ids[3]};
            } else if (cnt['h'] > 2 || cnt['i'] > 1 || cnt['o'] > 1) {
                vector<int> new_ids;

                bool remain = false;

                for (int j = 0; j < ids.size(); j++) {
                    int id = ids[j];
                    if (remain) {
                        new_ids.push_back(id);
                    } else {
                        if ((cnt['h'] > 2 && s[id] == 'h') ||
                            (cnt['i'] > 1 && s[id] == 'i') ||
                            (cnt['o'] > 1 && s[id] == 'o')) {
                            remain = true;
                        }
                        cnt[s[id]]--;
                    }
                }

                ids = new_ids;
            }
        }

        i++;
    }

    cout << min_len << endl;

    return 0;
}

