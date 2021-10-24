class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        
        auto last_double = vector<int>{2, INT_MAX};
        
        int last_min = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > last_double[1]) {
                 return true;
            } else if (nums[i] > last_double[0] && nums[i] < last_double[1]) {
                last_double[1] = nums[i];
            } else if (nums[i] < last_double[0] && nums[i] > last_min) {
                last_double[0] = last_min;
                last_double[1] = nums[i];
            } else if (nums[i] < last_min) {
                last_min = nums[i];
            }
        }
        
        return false;
    }
};