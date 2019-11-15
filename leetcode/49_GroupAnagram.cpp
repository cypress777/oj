class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, string> dict;
        for (auto const &str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            dict[str] = s;
        }

        unordered_map<string, vector<string>> res;
        for (auto const &str : strs) {
            if (res.find(dict[str]) == res.end()) {
                res[dict[str]] = {str};
            } else {
                res[dict[str]].push_back(str);
            }
        }

        vector<vector<string>> ans;
        for (auto const &r : res) ans.push_back(r.second);

        return ans;
    }
};
