//! https://leetcode.com/problems/n-queens/

class Solution {
    vector<vector<string>> solutions;
    vector<string> b;
    vector<bool> rows;
    vector<bool> cols;
    vector<bool> negDiag;
    vector<bool> posDiag;
    int n;
    
public:
    
    bool inline canAttack(int x, int y) {
        // check rows and columns
        if (rows[x])
            return true;
        if (cols[y])
            return true;
        
        // check diagonals
        if (posDiag[n + x + y])
            return true;
        if (negDiag[n + y - x])
            return true;
        return false;
    }
    
    // set queen in row x x
    void solve(int x) {
        // reached last row => found solution
        if (x == n) {
            solutions.push_back(b);
            return;
        }
        
        for (int y = 0; y < n; y++) {
            if (!canAttack(x, y)) {
                b[x][y] = 'Q';
                rows[x] = true;
                cols[y] = true;
                posDiag[n + x + y] = true;
                negDiag[n + y - x]  = true;
                solve(x+1);
                b[x][y] = '.';
                rows[x] = false;
                cols[y] = false;
                posDiag[n + x + y] = false;
                negDiag[n + y - x]  = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        b = vector<string>(n, string(n, '.'));
        rows.resize(n);
        cols.resize(n);
        posDiag.resize(2*n);
        negDiag.resize(2*n);
        this->n = n;
        solve(0);
        return solutions;
    }
};
