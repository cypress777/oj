class Solution {
public:
    void gen(const string &digits, int id, string &s,
             unordered_map<int, string> &phone, set<string> &res) {
        if (id >= digits.size()) {
            res.insert(s);
        } else {
            int num = digits[id] - '0';
            string letters = phone[num];
            for (int i = 0; i < letters.size(); i++) {
                string next = s;
                next.push_back(letters[i]);

                gen(digits, id + 1, next, phone, res);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> phone = {{2, "abc"}, {3, "def"}, {4, "ghi"},
                                            {5, "jkl"}, {6, "mno"}, {7, "pqrs"},
                                            {8, "tuv"}, {9, "wxyz"}};

        set<string> res;
        string empty;
        gen(digits, 0, empty, phone, res);

        vector<string> uniq_res;
        for (auto r : res) {
            if (!r.empty()) uniq_res.push_back(r);
        }
        return uniq_res;
    }
};
