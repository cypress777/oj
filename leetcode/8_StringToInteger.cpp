class Solution {
public:
    int myAtoi(string str) {
        bool start = false;
        int res = 0;
        int sign = 1;
        for (int i = 0; i < str.size(); i++) {
            if (!start && str[i] == ' ') continue;

            if (!start && (str[i] == '-' || str[i] == '+')) {
                start = true;
                if (str[i] == '-') sign = -1;
                if (i == str.size() - 1) return 0;
                continue;
            }

            start = true;

            if (str[i] >= '0' && str[i] <= '9') {
                int pop = str[i] - '0';

                if (res > INT_MAX / 10 ||
                    (res == INT_MAX / 10 && pop > 7)) {
                    return INT_MAX;
                }

                if (res < INT_MIN / 10 ||
                    (res == INT_MIN / 10 && pop > 8)) {
                    return INT_MIN;
                }

                res = res * 10 + sign * pop;
            } else {
                break;
            }
        }

        return res;
    }
};