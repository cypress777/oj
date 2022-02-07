class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        
        int last = 0;
        int cur_val = 1;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur_val *= nums[i];
            
            if (cur_val >= k) {
                int j = last;
                
                while (j <= i) {
                    cnt += (i - j);
                    cur_val /= nums[j];
                    j++;
                    if (cur_val < k) break;
                }
                
                last = j;
            }
        }
        
        if (cur_val < k) {
            cnt += (nums.size() - last + 1) * (nums.size() - last) / 2;
        } else {
            cnt += (nums.size() - last) * (nums.size() - last - 1) / 2;
        }
        
        return cnt;
    }
};