class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};

        vector<char> stack(s.size(), '*');
        int cur = -1;

        for (int i = 0; i < s.size(); i++) {
            if (cur >= 0 && stack[cur] == pairs[s[i]]) {
                cur--;
            } else {
                stack[cur + 1] = s[i];
                cur++;
            }
        }

        return cur < 0;
    }
};
