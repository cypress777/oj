#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results{};
        
        sort(nums.begin(), nums.end());
        
        int i = 0;
        
        while (i + 2 < nums.size()) {
            int cur = nums[i];
            
            auto sums = twoSum(nums, i + 1, nums.size() - 1, -nums[i]);
            
            for (auto sum : sums) {
                results.push_back(vector<int>{nums[i], sum[0], sum[1]});
            }
            
            while (i < nums.size() && nums[i] == cur) i++;
        }
        return results;
    }
    
    vector<vector<int>> twoSum(const vector<int>& nums, int left, int right, int target) {
        auto result = vector<vector<int>>{};
        
        while (left < right && left >= 0 && right < nums.size()) {
            int l_val = nums[left], r_val = nums[right];
            if (l_val > target - l_val) break;
            if (r_val < target - r_val) break;
            
            if (l_val + r_val == target) {
                result.push_back(vector<int>{l_val, r_val});
                while (left < nums.size() && nums[left] == l_val) left++;
                while (right >= 0 && nums[right] == r_val) right--;
            } else if (l_val + r_val > target) {
                while (right >= 0 && nums[right] == r_val) right--;
            } else {
                while (left < nums.size() && nums[left] == l_val) left++;
            }
        }
        return result;
    }
};