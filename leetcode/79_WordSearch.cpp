class Solution {
public:
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};

    bool is_valid(int r, int c, int id,
                  const vector<vector<char>>& board,
                  const vector<vector<int>> &flg,
                  const string &word) {
        if (id == word.size() - 1) return true;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];

            if (nr < 0 || nr >= board.size() ||
                nc < 0 || nc >= board[0].size()) continue;

            if (board[nr][nc] != word[id + 1]) continue;

            if (flg[nr][nc] > 0) continue;

            vector<vector<int>> nflg = flg;
            nflg[nr][nc] = 1;

            if (is_valid(nr, nc, id + 1, board, nflg, word)) return true;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty()) return false;

        int r = board.size();
        int c = board[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] != word[0]) continue;

                vector<vector<int>> flg(r, vector<int>(c, -1));
                flg[i][j] = 1;
                if (is_valid(i, j, 0, board, flg, word)) return true;
            }
        }

        return false;
    }
};

