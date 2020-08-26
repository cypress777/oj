class Solution {
public:
    string longestPalindrome(string s) {
        int ss = s.size();

        vector<bool> even(ss, true);
        vector<bool> odd(ss, true);
        int max_len = 1;
        int max_id = 0;
        for (int len = 2; len <= ss; len++) {
            for (int i = 0; i < ss; i++) {
                bool is_odd = len % 2;

                if (is_odd) {
                    if (i < len / 2 || i > ss - len / 2) continue;

                    if (odd[i] && s[i - len / 2] == s[i + len / 2]) {
                        if (max_len < len) {
                            max_id = i;
                            max_len = len;
                        }
                    } else {
                        odd[i] = false;
                    }
                } else {
                    if (i < len / 2 - 1 || i > ss - len / 2) continue;

                    if (even[i] && s[i - (len - 1) / 2] == s[i + len / 2]) {
                        if (max_len < len) {
                            max_id = i;
                            max_len = len;
                        }
                    } else {
                        even[i] = false;
                    }
                }
            }
        }

        string res;
        for (int i = max_id - (max_len - 1) / 2; i <= max_id + max_len / 2; i++) {
            res.push_back(s[i]);
        }

        return res;
    }
};