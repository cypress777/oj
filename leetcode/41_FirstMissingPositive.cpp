class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == i) continue;
            if (nums[i] < 0 || nums[i] >= nums.size()) {
                nums[i] = -1;
                continue;
            }

            int p = nums[i];
            nums[i] = -1;
            while (p >= 0 && p < nums.size() && nums[p] != p) {
                int tmp = nums[p];
                nums[p] = p;
                p = tmp;
            }
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != i) {
                return i;
                break;
            }
        }

        return nums.size();
    }
};
