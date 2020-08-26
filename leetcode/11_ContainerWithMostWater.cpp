class Solution {
public:
    int maxArea(vector<int>& height) {
        int p = 0, q = height.size() - 1;
        int max_volume = 0;

        while (p < q) {
            max_volume = max(max_volume, min(height[p], height[q]) * (q - p));

            if (height[p] < height[q]) {
                int n = p + 1;
                while (n <= q && height[n] <= height[p]) n++;
                p = n;
            } else {
                int n = q - 1;
                while (n >= p && height[n] <= height[q]) n--;
                q = n;
            }
        }

        return max_volume;
    }
};