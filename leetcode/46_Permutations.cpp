class Solution {
public:
    void gen(const vector<int> &current, const vector<int> &remain,
             vector<vector<int>> &res) {
        if (remain.empty()) res.push_back(current);

        for (int i = 0; i < remain.size(); i++) {
            vector<int> next = current;
            next.push_back(remain[i]);

            vector<int> next_remain;
            for (int j = 0; j < remain.size(); j++) {
                if (j != i) next_remain.push_back(remain[j]);
            }

            gen(next, next_remain, res);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> init;
        vector<vector<int>> res;
        gen(init, nums, res);

        return res;
    }
};
