class Solution {
public:
    bool bi_search(const vector<vector<int>>& matrix, int target, int sr, int sc, int er, int ec) {
        int mr = sr + (er - sr) / 2;
        int mc = sc + (ec - sc) / 2;
        // cout << "====== " << sr << " " << sc << " " << er << " " << ec << endl;
        // cout << "-- " << mr << " " << mc << endl;
        
        if (sr > er || sc > ec) return false;
        
        if (matrix[mr][mc] == target) return true;
        if (matrix[sr][sc] > target) return false;
        if (matrix[er][ec] < target) return false;
        // cout << "-- " << matrix[mr][mc] << endl;
        if (sr == er && sc == ec) return false;
        
        if (matrix[mr][mc] > target) {
            return (
                bi_search(matrix, target, sr, sc, mr - 1, mc - 1) ||
                bi_search(matrix, target, sr, mc, mr - 1, ec) || 
                bi_search(matrix, target, mr, sc, er, mc - 1)
            );
        } else {
            return (
                bi_search(matrix, target, sr, mc + 1, mr, ec) || 
                bi_search(matrix, target, mr + 1, sc, er, mc) ||
                bi_search(matrix, target, mr + 1, mc + 1, er, ec)
            );
        }
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        return bi_search(matrix, target, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
    }
};