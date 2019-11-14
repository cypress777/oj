class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int p = 0, q = -1;
        int res = 0;

        while (p < height.size() - 1) {
            if (height[p] <= height[p + 1]) {
                p++;
                continue;
            }

            int t = p + 1;
            int tmp = height[t];
            int tmp_id = t;
            while (t < height.size()) {
                if (height[t] > tmp) {
                    tmp = height[t];
                    tmp_id = t;
                }
                if (height[t] >= height[p] || t == height.size() - 1) break;
                t++;
            }
            q = tmp_id;

            int h = min(height[p], height[q]);
            int vol = h * (q - p - 1);
            for (int i = p + 1; i < q; i++) {
                vol -= min(h, height[i]);
            }
            // cout << p << " " << q << " " << vol << endl;

            res += vol;

            p = q;
        }

        return res;
    }
};
