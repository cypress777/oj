class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 2; i <= n; i++) {
            // cout << s << endl;
            string ns = "";
            int len = 0;
            for (int j = 0; j < s.size(); j++) {
                if (j == 0 || s[j] == s[j - 1]) {
                    len++;
                } else {
                    ns.push_back('0' + len);
                    ns.push_back(s[j - 1]);
                    len = 1;
                }

                if (j == s.size() - 1) {
                    ns.push_back('0' + len);
                    ns.push_back(s[j]);
                }
            }
            s = ns;
        }

        return s;
    }
};
