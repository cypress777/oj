class Solution {
public:
    void gen(int n, int p, const string &s, set<string> &res) {
        if (n == 0 && p == -1) {
            res.insert(s);
        } else if (n >= 0) {
            if (p >= 0) {
                string ns = s;
                ns.push_back(')');
                gen(n, p - 1, ns, res);
            }

            if (n > 0) {
                string ns = s;
                ns.push_back('(');
                gen(n - 1, p + 1, ns, res);
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        string dumb;
        set<string> res;
        gen(n, -1, dumb, res);

        vector<string> uniq_res;
        for (auto r : res) uniq_res.push_back(r);

        return uniq_res;
    }
};
