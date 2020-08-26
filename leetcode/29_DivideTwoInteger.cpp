class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;

        int dvd = dividend;
        if (dividend > 0) dvd = 0 - dividend;
        int dvs = divisor;
        if (divisor > 0) dvs = 0 - divisor;

        vector<int> tab;
        int n = dvs;
        while (n >= INT_MIN) {
            tab.push_back(n);

            if (n < (INT_MIN + 1) >> 1) break;
            n += n;
        }

        // for (int i = 0; i < tab.size(); i++) {
        //     cout << i << " " << tab[i] << endl;
        // }

        int res = 0;
        for (int i = tab.size() - 1; i >= 0; i--) {
            while (dvd <= tab[i]) {
                dvd -= tab[i];

                if (i == 31) {
                    res = INT_MIN;
                } else {
                    res -= (1 << i);
                }

                // cout << "--- " << i << " " << tab[i] << " " << res << endl;
            }
        }

        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
            if (res <= INT_MIN + 1) return INT_MAX;
            return 0 - res;
        } else {
            return res;
        }
    }
};
