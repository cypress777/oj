class Solution {
public:
    vector<bool> tab;
    vector<bool> vst;
    unordered_set<string> dict;
    string ori_s;

    bool helper(int id) {
        if (id >= ori_s.size()) return false;
        if (vst[id]) return tab[id];

        // cout << "--- " << id << endl;

        vst[id] = true;

        for (int i = id; i < ori_s.size(); i++) {
            string new_s;
            for (int j = id; j <= i; j++) new_s.push_back(ori_s[j]);

            if (dict.find(new_s) == dict.end()) continue;
            // cout << "-- " << i << " " << new_s << endl;

            if (i + 1 >= ori_s.size() || helper(i + 1)) {
                // cout << "--- " << id << endl;
                tab[id] = true;
                return true;
            }
        }

        // cout << "--- " << id << endl;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        ori_s = s;

        dict.clear();
        for (const string &w : wordDict) dict.insert(w);

        tab = vector<bool>(s.size(), false);
        vst = vector<bool>(s.size(), false);

        return helper(0);
    }
};
