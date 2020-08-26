class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        if (matrix.size() == 0 || matrix[0].size() == 0) return res;

        int R = matrix.size();
        int C = matrix[0].size();

        for (int k = 0; k < min(R, C) / 2; k++) {
            vector<int> rows = {k, k, R - 1 - k, R - 1 - k};
            vector<int> cols = {k, C - 1 - k, C - 1 - k, k};

            for (int i = cols[0]; i < cols[1]; i++) {
                res.push_back(matrix[rows[0]][i]);
            }

            for (int i = rows[1]; i < rows[2]; i++) {
                res.push_back(matrix[i][cols[1]]);
            }

            for (int i = cols[2]; i > cols[3]; i--) {
                res.push_back(matrix[rows[2]][i]);
            }

            for (int i = rows[3]; i > rows[0]; i--) {
                res.push_back(matrix[i][cols[3]]);
            }
        }

        if (min(R, C) % 2 == 1) {
            if (R < C) {
                int k = R / 2;
                for (int i = k; i <= C - 1 - k; i++) {
                    res.push_back(matrix[k][i]);
                }
            } else {
                int k = C / 2;
                for (int i = k; i <= R - 1 - k; i++) {
                    res.push_back(matrix[i][k]);
                }
            }
        }

        return res;
    }
};
