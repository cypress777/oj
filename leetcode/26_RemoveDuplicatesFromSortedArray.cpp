class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (p < 0 || nums[i] != nums[p]) {
                if (i > p + 1) nums[p + 1] = nums[i];
                p++;
            }
        }
        return p + 1;
    }
};
