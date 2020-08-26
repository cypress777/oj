class Solution {
public:
    set<int> showup;
    
    int calc(int n) {
        int res = 0;
        while(n > 0) {
            res += pow(n % 10, 2);
            n = n / 10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        int next = n;
        while(next != 1 && showup.find(next) == showup.end()) {
            showup.insert(next);
            next = calc(next);
        }
        
        if (next == 1) {
            return true;
        } else {
            return false;
        }
    }
};
