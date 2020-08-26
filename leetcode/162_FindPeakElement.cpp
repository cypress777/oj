class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, m = (l + r) / 2;

        while (l < r) {
            // cout << l << " " << m << " " << r << endl;
            if (nums[m] < nums[m + 1]) {
                l = m + 1;
            } else {
                r = m;
            }
            m = (l + r) / 2;
        }

        return l;
    }
};
