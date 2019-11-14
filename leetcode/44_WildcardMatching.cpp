class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> table(p.size() + 1, vector<bool>(s.size() + 1, false));
        table[p.size()][s.size()] = true;

        int last_match = s.size();

        for (int i = p.size() - 1; i >= 0; i--) {
            if (p[i] != '*') {
                last_match = -1;

                for (int j = s.size(); j >= 0; j--) {
                    if (j == s.size()) {
                        table[i][j] = false;
                        continue;
                    }

                    table[i][j] = (table[i + 1][j + 1] &&
                                   (p[i] == s[j] || p[i] == '?'));
                    if (table[i][j] && last_match == -1) last_match = j;
                }
            } else {
                if (last_match == -1) continue;

                for (int j = last_match; j >= 0; j--) {
                    table[i][j] = true;
                }
            }
        }

        // for (int i = p.size(); i >= 0; i--) {
        //     for (int j = s.size(); j >= 0; j--) {
        //         cout << table[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return table[0][0];
    }
};
