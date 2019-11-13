class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int cur = 0;
        bool stop = false;
        string res;

        while (!stop) {
            if (strs.empty() || cur >= strs[0].size()) break;

            char tmp = strs[0][cur];

            for (auto const &s : strs) {
                if (cur >= s.size() || s[cur] != tmp) {
                    stop = true;
                    break;
                }
            }

            if (!stop) res.push_back(tmp);
            cur++;
        }

        return res;
    }
};
