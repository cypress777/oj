class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;

        vector<int> ways(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    ways[j] = 1;
                } else {
                    if (j > 0) ways[j] += ways[j - 1];
                }
            }
        }

        return ways[n - 1];
    }
};
