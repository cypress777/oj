class Solution {
public:
    static bool comp(const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) return res;

        sort(intervals.begin(), intervals.end(), comp);

        vector<int> tmp = intervals[0];
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] <= tmp[1]) {
                tmp[1] = max(tmp[1], intervals[i][1]);
            } else {
                res.push_back(tmp);
                tmp = intervals[i];
            }

            if (i == intervals.size() - 1) {
                res.push_back(tmp);
            }
        }
        return res;
    }
};
