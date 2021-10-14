#include<vector>
using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto swap = [&](int i, int j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        };
        
        int left = 0, right = nums.size() - 1;
        int cur = left;
        while (cur <= right) {
            if (nums[cur] == 0) {
                swap(left, cur);
                left++;
                cur++;
            } else if (nums[cur] == 2) {
                swap(cur, right);
                right--;
            } else {
                cur++;
            }
        }
    }
};