class Solution {
public:
    bool isStrobogrammatic(string num) {
        vector<int> strobo(10, -1);
        strobo[0] = 0;
        strobo[1] = 1;
        strobo[6] = 9;
        strobo[8] = 8;
        strobo[9] = 6;
        
        for (int i = 0; i < (num.size() + 1) / 2; i++) {
            int j = num.size() - 1 - i;
            int ni = num[i] - '0';
            int nj = num[j] - '0';
            if (strobo[ni] != nj) return false;
        }
        return true;
    }
};

class Solution1 {
public:
    void expand(string s, int n, const unordered_map<int, int>& strobos, vector<string> &res) {
        if (s.size() == n) {
            if (n == 1 || s[0] != '0') res.push_back(s);
            return;
        }
        
        for (auto strobo : strobos) {
            expand(to_string(strobo.first) + s + to_string(strobo.second), n, strobos, res);
        }
    }
    
    vector<string> findStrobogrammatic(int n) {
        unordered_map<int, int> strobos;
        strobos[0] = 0;
        strobos[1] = 1;
        strobos[6] = 9;
        strobos[8] = 8;
        strobos[9] = 6;
        
        vector<string> res;
        if (n % 2 == 0) {
            expand("", n, strobos, res);
        } else {
            expand("0", n, strobos, res);
            expand("1", n, strobos, res);
            expand("8", n, strobos, res);
        }
        return res;
    }
};