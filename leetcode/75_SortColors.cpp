class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p = -1, q = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            while (p + 1 < nums.size() && nums[p + 1] == 0) p++;
            while (q - 1 >= 0 && nums[q - 1] == 2) q--;
            if (i <= p) continue;
            if (i >= q) break;

            if (nums[i] == 2) {
                if (nums[q - 1] == 0) {
                    nums[p + 1] = 0;
                    p++;
                }
                nums[q - 1] = 2;
                q--;
            } else if (nums[i] == 0) {
                nums[p + 1] = 0;
                p++;
            }
            if (i > p && i < q) nums[i] = 1;
        }
    }
};
