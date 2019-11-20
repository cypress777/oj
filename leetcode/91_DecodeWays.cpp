class Solution {
public:
    int numDecodings(string s) {
        vector<int> ways(s.size() + 1, 0);
        ways[s.size()] = 1;
        if (s[s.size() - 1] != '0') ways[s.size() - 1] = 1;

        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i] != '0') ways[i] = ways[i + 1];

            if (s[i] == '1' || (s[i] == '2' && s[i + 1] - '0' < 7)) {
                ways[i] += ways[i + 2];
            }
        }

        // for (int i = 0; i < ways.size() - 1; i++) cout << s[i] << " " << ways[i] << endl;

        return ways[0];
    }
};
