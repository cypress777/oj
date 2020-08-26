class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ns = nums.size();
        vector<int> reach(ns, 0);

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                reach[i] = i + nums[i];
            } else {
                if (reach[i - 1] < i) return false;
                reach[i] = max(reach[i - 1], i + nums[i]);
            }
        }

        return true;
    }
};
