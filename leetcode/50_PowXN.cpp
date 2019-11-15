class Solution {
public:
    double pow(double x, int n) {
        double base = x;
        double res = 1.0;
        while (n > 0) {
            if (n % 2 == 1) res *= base;
            base *= base;
            n = n / 2;
        }
        return res;
    }

    double myPow(double x, int n) {
        if (n > 0) {
            return pow(x, n);
        } else {
            if (n == INT_MIN) {
                return 1 / (pow(x, -(n + 1)) * x);
            } else {
                return 1 / pow(x, -n);
            }
        }
    }
};
