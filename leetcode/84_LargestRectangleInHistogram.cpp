class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size(), 0);
        for (int i = 1; i < heights.size(); i++) {
            int p = i - 1;
            while (p >=0 && heights[p] >= heights[i]) {
                p = left[p] - 1;
            }
            left[i] = p + 1;
        }

        vector<int> right(heights.size(), heights.size() - 1);
        for (int i = heights.size() - 2; i >= 0; i--) {
            int p = i + 1;
            while (p < heights.size() && heights[p] >= heights[i]) {
                p = right[p] + 1;
            }
            right[i] = p - 1;
        }

        int max_val = 0;
        for (int i = 0; i < heights.size(); i++) {
            int val = heights[i] * (right[i] - left[i] + 1);
            // cout << i << " " << heights[i] << " " << left[i] << " " << right[i] << endl;
            max_val = max(val, max_val);
        }

        return max_val;
    }
};
