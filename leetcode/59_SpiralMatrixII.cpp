#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        auto result = vector<vector<int>>(n, vector<int>(n));
        
        int mid = n / 2;
        int l_t = 1;
        for (int i = 0; i < mid; i++) {
            int step = n - 2 * i - 1;
            int r_t = l_t + step, r_b = r_t + step, l_b = r_b + step;
            
            for (int j = i; j < n - 1 - i; j++) {
                int increase = j - i;
                result[i][j] = l_t + increase;
                result[j][n - 1 - i] = r_t + increase;
                result[n - 1 - i][n - 1 - j] = r_b + increase;
                result[n - 1 - j][i] = l_b + increase;
            }
            
            l_t = l_b + step;
        }
        if (n % 2 == 1) result[mid][mid] = n * n;
        
        return result;
    }
};