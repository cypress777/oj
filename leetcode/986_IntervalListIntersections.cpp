#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        auto result = vector<vector<int>>{};
        
        int first_cur = 0, second_cur = 0;
        
        while (first_cur < firstList.size() && second_cur < secondList.size()) {
            int start = max(firstList[first_cur][0], secondList[second_cur][0]), end = min(firstList[first_cur][1], secondList[second_cur][1]);
            
            if (start <= end) {
                result.push_back({start, end});
                
                if (firstList[first_cur][1] == secondList[second_cur][1]) {
                    first_cur++;
                    second_cur++;
                } else if (firstList[first_cur][1] > end) {
                    second_cur++;
                } else {
                    first_cur++;
                }
            } else {
                if (firstList[first_cur][1] < secondList[second_cur][0]) {
                    first_cur++;
                } else {
                    second_cur++;
                }
            }
        }
        
        return result;
    }
};
