class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n / 2; i++) {
            int l = n - 2 * i - 1;
            // cout << "--- " << i << " " << l << endl;

            for (int j = 0; j < l; j++) {
                vector<int> rs = {i, i + j, n - 1 - i, n - 1 - i - j};
                vector<int> cs = {i + j, n - 1 - i, n - 1 - i - j, i};
                // for (int t = 0; t < 4; t++) {
                //     cout << rs[t] << " " << cs[t] << endl;
                // }

                int last = matrix[rs[3]][cs[3]];
                for (int t = 0; t < 4; t++) {
                    int r = rs[t], c = cs[t];
                    int tmp = matrix[r][c];
                    matrix[r][c] = last;
                    last = tmp;
                }
            }
        }
    }
};
