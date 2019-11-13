class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));

        dp[s.size()][p.size()] = true;

        for (int i = s.size(); i >= 0; i--) {
            for (int j = p.size() - 1; j >= 0; j--) {
                bool now_match = (i < s.size() && (p[j] == s[i] || p[j] == '.'));

                if (j < p.size() - 1 && p[j + 1] == '*') {
                    dp[i][j] = (dp[i][j + 2] || (now_match && dp[i + 1][j]));
                } else {
                    dp[i][j] = (now_match && dp[i + 1][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};
