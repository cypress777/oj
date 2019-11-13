class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ns = nums.size();

        // find start
        int p = 0, q = ns - 1;
        int m = (p + q) / 2;
        while (p < q) {
            if (nums[m] > nums[q]) {
                p = m + 1;
            } else {
                q = m;
            }
            m = (p + q) / 2;
        }
        // cout << m << endl;

        // find target
        int start = m;
        p = 0;
        q = ns - 1;
        m = (p + q) / 2;

        while (p <= q) {
            int id = (start + m) % ns;

            if (nums[id] > target) {
                q = m - 1;
            } else if (nums[id] < target) {
                p = m + 1;
            } else {
                return id;
            }
            m = (p + q) / 2;
        }

        return -1;
    }
};
