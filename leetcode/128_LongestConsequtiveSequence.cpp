class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> tab;
        for (int i = 0; i < nums.size(); i++) tab[nums[i]] = i;

        vector<int> vst(nums.size(), -1);
        int max_len = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (vst[i] != -1) continue;
            vst[i] = 1;

            int p = nums[i] - 1, q = nums[i] + 1;
            while (tab.find(p) != tab.end()) {
                vst[tab[p]] = 1;
                p--;
            }

            while (tab.find(q) != tab.end()) {
                vst[tab[q]] = 1;
                q++;
            }

            int cur_len = q - p - 1;

            // cout << i << " " << nums[i] << " " << q << " " << p << " " << cur_len << endl;
            max_len = max(cur_len, max_len);
        }

        return max_len;
    }
};
