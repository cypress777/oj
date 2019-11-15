class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ns = nums.size();
        vector<int> reach(ns, 0);
        vector<int> reachable(ns, false);

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                reachable[i] = true;
                reach[i] = i + nums[i];
            } else {
                reachable[i] = (reach[i - 1] >= i);
                if (reachable[i]) reach[i] = max(reach[i - 1], i + nums[i]);
            }
        }

        return reachable[nums.size() - 1];
    }
};
