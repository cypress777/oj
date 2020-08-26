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

    // dfs
    vector<vector<int>> permute0(vector<int>& nums) {
        vector<int> init;
        vector<vector<int>> res;
        gen(init, nums, res);

        return res;
    }

    // permutation
    vector<vector<int>> permute(vector<int>& nums) {
        int ns = nums.size();

        vector<int> tab(ns + 1);
        tab[0] = 1;
        int fac = 1;
        for (int i = 1; i <= ns; i++) {
            fac *= i;
            tab[i] = fac;
        }

        vector<vector<int>> res;
        for (int k = 0; k < tab[ns]; k++) {
            vector<int> flg(ns, 0);
            vector<int> tmp;
            int t = k;

            for (int i = ns - 1; i >= 0; i--) {
                int n = t / tab[i];

                int rn = -1;
                for (int j = 0; j < ns; j++) {
                    if (flg[j] == -1) continue;

                    rn++;

                    if (rn == n) {
                        tmp.push_back(nums[j]);
                        flg[j] = -1;
                        break;
                    }
                }

                t = t % tab[i];
            }

            res.push_back(tmp);
        }

        return res;
    }
};
