class Solution {
public:
    int maxSubArray0(vector<int>& nums) {
        int val = nums[0], p = 0, q = 0;
        int max_val = nums[0], max_p = 0, max_q = 0;

        while (p < nums.size() && q < nums.size()) {
            if (val > max_val) {
                max_val = val;
                max_p = p;
                max_q = q;
            }

            q++;
            if (val <= 0) {
                p = q;
                val = 0;
            }

            if (p < nums.size() && q < nums.size()) val += nums[q];
        }

        return max_val;
    }

    // divide and conquer
    int maxSubArray1(vector<int>& nums) {
        vector<int> tail(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                tail[i] = nums[i];
            } else {
                tail[i] = nums[i] + max(0, tail[i - 1]);
            }
        }

        vector<int> sub(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                sub[i] = nums[i];
            } else {
                sub[i] = max(sub[i - 1], tail[i]);
            }
        }

        return sub[sub.size() - 1];
    }
};
