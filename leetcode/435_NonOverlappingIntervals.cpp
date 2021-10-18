#include<vector>
using namespace std;


bool comp(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        
        int last = 0, cur = 1;
        int cnt = 0;
        while (cur < intervals.size()) {
            if (intervals[cur][0] >= intervals[last][1]) {
                last = cur;
            } else if (intervals[cur][1] <= intervals[last][1]) {
                cnt++;
                last = cur;
            } else {
                cnt++;
            }
            cur++;
        }
        
        return cnt;
    }
};
