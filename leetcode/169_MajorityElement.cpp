class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int last = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (cnt == 0) {
                last = nums[i];
                cnt++;
            } else {
                if (nums[i] == last) {
                    cnt++;
                } else {
                    cnt--;
                }
            }
        }

        return last;
    }
};
