class Solution {
public:
    void get_lps(const string & s, vector<int> &lps) {
        lps = vector<int>(s.size(), 0);

        for (int i = 1; i < s.size(); i++) {
            int len = lps[i - 1];

            while (len >= 0 && s[i] != s[len]) {
                len = (len > 0 ? lps[len - 1] : -1);
            }

            lps[i] = len + 1;
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        vector<int> lps;
        get_lps(needle, lps);

        int p = 0, q = 0;
        while (p < haystack.size()) {
            if (haystack[p] == needle[q]) {
                if (q == needle.size() - 1) return p - needle.size() + 1;

                p++;
                q++;
            } else {
                if (q == 0) p++;
                else q = lps[q - 1];
            }
        }

        return -1;
    }
};
