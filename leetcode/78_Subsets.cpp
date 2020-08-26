class Solution {
public:
    void gen(const vector<int> &cur,
             int id,
             const vector<int> &remain,
             vector<vector<int>> &res) {
        res.push_back(cur);

        for (int i = id; i < remain.size(); i++) {
            vector<int> next = cur;
            next.push_back(remain[i]);

            gen(next, i + 1, remain, res);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        gen(cur, 0, nums, res);

        return res;
    }
};
