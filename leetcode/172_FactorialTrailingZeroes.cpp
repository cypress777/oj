class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        int d = 5;
        while (d <= n) {
            res += n / d;
            if (n / d < 5) break;
            d *= 5;
        }
        return res;
    }
};
