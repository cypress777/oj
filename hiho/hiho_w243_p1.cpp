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

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'h' || s[i] == 'i' || s[i] == 'o') {
            cnt[s[i]]++;

//            cout << s[i] << "  " << cnt['h'] << " " << cnt['i'] << " " << cnt['o'] << endl;
            ids.push_back(i);

            sort(ids.begin(), ids.end());

            if (cnt['h'] == 2 && cnt['i'] == 1 && cnt['o'] == 1) {
                int len = i - ids[0] + 1;

                if (min_len == -1 || len < min_len) min_len = len;

                ids = {ids[1], ids[2], ids[3]};
                cnt[s[ids[0]]]--;
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
    }

    cout << min_len << endl;

    return 0;
}

