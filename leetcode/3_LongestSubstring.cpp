class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_showed;
        int left = 0, right = 0;
        int max_len = 0;

        while (right < s.size()) {
            if (last_showed.find(s[right]) != last_showed.end() &&
                last_showed[s[right]] >= left) {
                left = last_showed[s[right]] + 1;
            }

            max_len = max(max_len, right - left + 1);
            last_showed[s[right]] = right;
            right++;
        }

        return max_len;
    }
};