class Solution {
public:
    // stack
    int trap(vector<int>& height) {
        vector<int> stack(height.size());
        int p = -1;
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            if (p == -1 || height[i] <= height[stack[p]]) {
                p++;
                stack[p] = i;
            } else {
                while (p >= 0 && height[i] > height[stack[p]]) {
                    int pop = stack[p];
                    p--;
                    if (p < 0) break;

                    int top = stack[p];

                    int dist = i - top - 1;
                    int h = min(height[top], height[i]) - height[pop];

                    res += dist * h;
                }
                p++;
                stack[p] = i;
            }
        }

        return res;
    }

    // two pointers
    int trap0(vector<int>& height) {
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

    // dynamic programming
    int trap1(vector<int>& height) {
        if (height.empty()) return 0;

        vector<int> left_bound(height.size());
        vector<int> right_bound(height.size());

        int max_val = height[0];
        for (int i = 0; i < height.size(); i++) {
            if (height[i] >= max_val) max_val = height[i];
            left_bound[i] = max_val;
        }

        max_val = height[height.size() - 1];
        for (int i = height.size() - 1; i >= 0; i--) {
            if (height[i] >= max_val) max_val = height[i];
            right_bound[i] = max_val;
        }

        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            int h = min(left_bound[i], right_bound[i]);
            res += (h - height[i]);
        }

        return res;
    }
};
