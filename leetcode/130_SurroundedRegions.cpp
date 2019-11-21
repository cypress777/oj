class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        int R = board.size();
        int C = board[0].size();
        vector<vector<int>> vst(R, vector<int>(C, -1));

        for (int r = 1; r < R - 1; r++) {
            for (int c = 1; c < C - 1; c++) {
                if (board[r][c] == 'X') continue;
                if (vst[r][c] != -1) continue;

                vst[r][c] = 1;

                vector<int> queue = {r * C + c};
                int p = 0, q = 0;
                bool need_flip = true;

                while (p <= q) {
                    int cr = queue[p] / C, cc = queue[p] % C;
                    p++;

                    for (int i = 0; i < 4; i++) {
                        int nr = cr + dr[i], nc = cc + dc[i];

                        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                        if (board[nr][nc] == 'X') continue;
                        if (vst[nr][nc] != -1) continue;

                        vst[nr][nc] = 1;

                        if (nr == 0 || nr == R - 1 || nc == 0 || nc == C - 1) need_flip = false;
                        queue.push_back(nr * C + nc);
                        q++;
                    }
                }

                if (need_flip) {
                    for (int id : queue) board[id / C][id % C] = 'X';
                }
            }
        }
    }
};
