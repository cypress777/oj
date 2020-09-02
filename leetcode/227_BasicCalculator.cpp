class Solution {
public:
    vector<long long> opd;
    vector<char> opt;
    int opd_top = -1, opt_top = -1;
    
    bool is_num(char c) {
        return (c >= '0' && c <= '9');
    }
    
    bool is_prior(char a, char b) {
        if ((a == '-' || a == '+') && (b == '*' || b == '/')) return false;
        return true;
    }
    
    long long calc(long long l, long long r, char opt) {
        if (opt == '+') return l + r;
        if (opt == '-') return l - r;
        if (opt == '*') return l * r;
        if (opt == '/') return l / r;
        return 0;
    }
    
    long long pop_top() {
        char pop_opt = opt[opt_top];
        opt_top--;

        long long r_opd = opd[opd_top];
        opd_top--;
        long long l_opd = opd[opd_top];
        opd_top--;

        return calc(l_opd, r_opd, pop_opt);
    }
    
    long long calculate(string s) {    
        opd = vector<long long>(s.size() + 1, 0);
        opt = vector<char>(s.size() + 1, ' ');
        
        long long result = 0;

        long long num = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            
            if (is_num(s[i])) {
                num = num * 10 + s[i] - '0';
                
                if (i == s.size() - 1 || !is_num(s[i + 1])) {
                    opd_top++;
                    opd[opd_top] = num;
                    num = 0;
                }
            } else {
                if (opt_top >= 0 && is_prior(opt[opt_top], s[i])) {
                    while (opt_top >= 0 && is_prior(opt[opt_top], s[i])) {
                        long long new_top_opd = pop_top();
                        opd_top++;
                        opd[opd_top] = new_top_opd;
                    }
                }
                opt_top++;
                opt[opt_top] = s[i];
            }
        }
        
        while (opt_top >= 0) {
            long long new_top_opd = pop_top();
            opd_top++;
            opd[opd_top] = new_top_opd;
        }
        result = opd[0];
        return result;
    }
};
