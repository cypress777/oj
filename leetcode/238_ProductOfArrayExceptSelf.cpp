class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto res = vector<int>(nums.size(), 0);
        
        int total = 1;
        int zero_cnt = 0;
        int zero_pos = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero_cnt++;
                zero_pos = i;
            } else {
                total *= nums[i];
            }
        }
        
        if (zero_cnt > 1) return res;
        if (zero_cnt == 1) {
            res[zero_pos] = total;
            return res;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            res[i] = total / nums[i];
        }
        
        return res;
    }
};