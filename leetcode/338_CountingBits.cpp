class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res{0};
        int power = 0;
        int len = pow(2, power);
        int ii = 0;
        
        for (int i = 1; i <= num; i++) {
            if (ii < len) {
                res.push_back(res[ii] + 1);
                // cout << i << " " << ii << " " << res[ii] + 1 << endl;
            } else {
                ii = 0;
                power += 1;
                len = pow(2, power);
                res.push_back(res[ii] + 1);
                // cout << i << " " << ii << " " << res[ii] + 1 << endl;
            }
            ii += 1;
        }
        
        return res;
    }
};
