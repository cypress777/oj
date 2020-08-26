class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        int last_row = 1, last_col = 1, last_val = matrix[r - 1][c - 1];

        for (int i = 0; i < r; i++) {
            if (matrix[i][c - 1] == 0) {
                last_col = 0;
                break;
            }
        }

        for (int i = 0; i < c; i++) {
            if (matrix[r - 1][i] == 0) {
                last_row = 0;
                break;
            }
        }

        for (int i = 0; i < r - 1; i++) {
            for (int j = 0; j < c - 1; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][c - 1] = 0;
                    matrix[r - 1][j] = 0;
                }
            }
        }

        for (int i = 0; i < r - 1; i++) {
            for (int j = 0; j < c - 1; j++) {
                if (matrix[i][c - 1] == 0 || matrix[r - 1][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (last_row == 0) {
            for (int i = 0; i < c; i++) matrix[r - 1][i] = 0;
        }

        if (last_col == 0) {
            for (int i = 0; i < r; i++) matrix[i][c - 1] = 0;
        }
    }
};
