class Solution {
public:
    static bool comp(int a, int b) {
        int oria = a, orib = b;
        if (a == 0) return false;
        if (b == 0) return true;

        string sa;
        while (a > 0) {
            sa.push_back(a % 10 + '0');
            a /= 10;
        }

        string sb;
        while (b > 0) {
            sb.push_back(b % 10 + '0');
            b /= 10;
        }

        string re_ab = sb + sa;
        string re_ba = sa + sb;
        // cout << sa << " " << sb << endl;
        // cout << re_ab << " " << re_ba << endl;
        for (int i = re_ab.size() - 1; i >= 0; i--) {
            if (re_ab[i] == re_ba[i]) continue;
            return re_ab[i] > re_ba[i];
        }

        return false;
    }

    string to_str(int n) {
        if (n == 0) return "0";
        string res;
        vector<int> digit;
        while (n > 0) {
            digit.push_back(n % 10);
            n /= 10;
        }
        for (int i = digit.size() - 1; i >= 0; i--) res.push_back(digit[i] + '0');
        return res;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);

        string s;
        for (auto n : nums) {
            s += to_str(n);
            if (s == "0") break;
        }
        return s;
    }
};
