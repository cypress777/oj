class Solution {
public:
    int reverse(int x) {
        int POS_INF = pow(2, 31) - 1;
        int NEG_INF = -1 * pow(2, 31);

        int n = x;

        int res = 0;
        while (n != 0) {
            int pop = n % 10;

            if (res > POS_INF / 10 || (res == POS_INF / 10 && pop > 7)) {
                return 0;
            }

            if (res < NEG_INF / 10 || (res == NEG_INF / 10 && pop > 8)) {
                return 0;
            }

            res = res * 10 + pop;
            n /= 10;
        }

        return res;
    }
};