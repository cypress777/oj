#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> left_sums(nums.size(), 0);
        unordered_map<int, vector<int>> left_sum_id;
        
        for (int i = 0; i < nums.size(); i++) {
            int left_sum = nums[i] + (i > 0 ? left_sums[i - 1] : 0);
            left_sums[i] = left_sum;
            if (left_sum_id.find(left_sum) == left_sum_id.end()) {
                left_sum_id.insert({left_sum, vector<int>{}});
            }
            left_sum_id[left_sum].push_back(i);
        }
        
        int all_sum = left_sums[nums.size() - 1];
        
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int previous_sum = i > 0 ? left_sums[i - 1] : 0;
            int next_sum = previous_sum + k;
            // cout << "=== " << i << " " << previous_sum << " " << next_sum << endl;
            
            if (left_sum_id.find(next_sum) != left_sum_id.end()) {
                auto right_id_pos = lower_bound(
                    left_sum_id[next_sum].begin(), 
                    left_sum_id[next_sum].end(), 
                    i
                );

                if (right_id_pos != left_sum_id[next_sum].end()) {
                    cnt += left_sum_id[next_sum].end() - right_id_pos;
                }
            }
        }
        return cnt;
    }
};