class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> max_pos(nums.size(), 0);
        vector<int> min_neg(nums.size(), 0);
        vector<bool> has_pos(nums.size(), false);
        vector<bool> has_neg(nums.size(), false);

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                max_pos[i] = nums[i];
                has_pos[i] = true;

                if (i > 0) {
                    if (has_pos[i - 1] && max_pos[i - 1] > 0) {
                        max_pos[i] = max_pos[i - 1] * nums[i];
                    }

                    if (has_neg[i - 1] && nums[i] > 0) {
                        min_neg[i] = nums[i] * min_neg[i - 1];
                        has_neg[i] = true;
                    }
                }
            } else {
                min_neg[i] = nums[i];
                has_neg[i] = true;

                if (i > 0) {
                    if (has_pos[i - 1] && max_pos[i - 1] > 0) {
                        min_neg[i] = max_pos[i - 1] * nums[i];
                    }

                    if (has_neg[i - 1]) {
                        max_pos[i] = min_neg[i - 1] * nums[i];
                        has_pos[i] = true;
                    }
                }
            }
            // cout << "--- " << i << " " << nums[i] << endl;
            // cout << has_pos[i] << " " << max_pos[i] << endl;
            // cout << has_neg[i] << " " << min_neg[i] << endl;
        }

        int res = 0;
        bool found = false;
        for (int i = 0; i < nums.size(); i++) {
            if (!found) {
                if (has_pos[i]) {
                    res = max_pos[i];
                    found = true;
                } else if (has_neg[i]) {
                    res = min_neg[i];
                    found = true;
                }
            } else {
                if (has_pos[i]) {
                    res = max(res, max_pos[i]);
                } else if (has_neg[i]) {
                    res = max(res, min_neg[i]);
                }
            }
        }

        return res;
    }
};
