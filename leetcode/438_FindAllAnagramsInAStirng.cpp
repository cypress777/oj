class Solution {
public:
    bool is_same(const vector<int> &a, const vector<int> &b) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        auto result = vector<int>{};
        
        if (s.size() < p.size()) return result;
        
        auto p_cnt = vector<int>(26, 0);
        for (char l : p) p_cnt[l - 'a']++;
        
        auto s_cnt = vector<int>(26, 0);
        for (int i = 0; i < p.size() - 1; i++) {
            s_cnt[s[i] - 'a']++;
        }
        
        for (int i = 0; i + p.size() - 1 < s.size(); i++) {
            s_cnt[s[i + p.size() - 1] - 'a']++;
            
            if (is_same(p_cnt, s_cnt)) result.push_back(i);
            
            s_cnt[s[i] - 'a']--;
        }
        
        return result;
    }
};