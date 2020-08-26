class Solution {
public:
    bool is_match(const unordered_map<char, int> &s_cnt,
                  const unordered_map<char, int> &t_cnt) {
        for (auto const &tc : t_cnt) {
            if (s_cnt.find(tc.first) == s_cnt.end() ||
                s_cnt.at(tc.first) < tc.second) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> t_cnt;
        for (int i = 0; i < t.size(); i++) {
            if (t_cnt.find(t[i]) == t_cnt.end()) t_cnt[t[i]] = 0;
            t_cnt[t[i]]++;
        }

        vector<int> next(s.size(), -1);
        int cur = -1;
        for (int i = s.size() - 1; i >= 0; i--) {
            next[i] = cur;
            if (t_cnt.find(s[i]) != t_cnt.end()) cur = i;
        }

        unordered_map<char, int> s_cnt;
        int p = -1, q = -1;
        int res_p = -1, res_q = -1, res_len = s.size() + 1;
        for (int i = 0; i < s.size(); i++) {
            if (t_cnt.find(s[i]) == t_cnt.end()) continue;

            q = i;
            if (p == -1) {
                p = i;
                s_cnt.clear();
            }
            if (s_cnt.find(s[i]) == s_cnt.end()) s_cnt[s[i]] = 0;
            s_cnt[s[i]]++;
            // cout << "--- " << p << " " << q << " " << res_p << " " << res_q << endl;

            while (is_match(s_cnt, t_cnt)) {
                // cout << "++ " << p << " " << q << endl;
                int len = q - p + 1;
                if (len <= res_len) {
                    res_p = p;
                    res_q = q;
                    res_len = len;
                }

                int next_p = next[p];
                if (next_p > q || next_p == -1) break;

                s_cnt[s[p]]--;
                p = next_p;
            }
        }

        string res;
        if (res_p == -1) return res;
        for (int i = res_p; i <= res_q; i++) res.push_back(s[i]);
        return res;
    }
};
