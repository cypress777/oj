class Solution {
public:
    string to_string(long long n) {
        if (n == 0) return "0";

        vector<int> digit;
        while (n > 0) {
            digit.push_back(n % 10);
            n /= 10;
        }

        string res;
        for (int i = digit.size() - 1; i >= 0; i--) res.push_back(digit[i] + '0');

        return res;
    }

    string fractionToDecimal(int numerator, int denominator) {
        long long nu = numerator, de = denominator;

        string sign;
        if ((nu <= 0 && de < 0) || (nu >= 0 && de >= 0)) sign = "";
        else sign = "-";

        nu = abs(nu);
        de = abs(de);

        string head = sign + to_string(nu / de);
        if (nu % de == 0) {
            return head;
        } else {
            head.push_back('.');
            nu = nu % de * 10;
        }

        string res = "", tail = "";
        map<pair<char, long long>, int> last_show;
        int id = 0;
        while (nu > 0) {
            char digit = (nu / de + '0');
            long long remain = nu % de;
            pair<char, long long> cur(digit, remain);

            if (last_show.find(cur) != last_show.end()) {
                int loop_start = last_show[cur];
                res = head;
                for (int i = 0; i < tail.size(); i++) {
                    if (i == loop_start) res.push_back('(');
                    res.push_back(tail[i]);
                }
                res.push_back(')');
                return res;
            }

            last_show[cur] = id;
            tail.push_back(digit);
            nu = remain * 10;
            id++;
        }

        res = head + tail;
        return res;
    }
};
