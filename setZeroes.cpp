// https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void xeroOut(vector<vector<int>>& matrix, int X, int Y) {
        for (int x = 0; x < matrix.size(); x++)
            if (matrix[x][Y] != 0)
                matrix[x][Y] = -1;
        for (int y = 0; y < matrix[X].size(); y++)
            if (matrix[X][y] != 0)
                matrix[X][y] = -1;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        for (int x = 0; x < matrix.size(); x++) {
            int y;
            for (y = 0; y < matrix[x].size(); y++)
                if (matrix[x][y] == 0) {
                    xeroOut(matrix, x, y);
                    break;
                }
        }
        for (int x = 0; x < matrix.size(); x++)
            for (int y = 0; y < matrix[x].size(); y++)
                if (matrix[x][y] == -1)
                    matrix[x][y] = 0;
    }
};

class Solution {
public:
    void zeroOutCol(vector<vector<int>>& matrix, int X, int markZeroes=false) {
        for (int y = 0; y < matrix[X].size(); y++)
            if (markZeroes && matrix[X][y] == 0)
                matrix[X][y] = 1;
            else
                matrix[X][y] = 0;
    }
    
    void zeroOutRow(vector<vector<int>>& matrix, int Y, int markZeroes=false) {
        for (int x = 0; x < matrix.size(); x++)
            if (markZeroes && matrix[x][Y] == 0)
                matrix[x][Y] = 1;
            else
                matrix[x][Y] = 0;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int zeroX = -1, zeroY = -1;
        
        for (int x = 0; x < matrix.size(); x++)
            for (int y = 0; y < matrix[x].size(); y++)
                if (matrix[x][y] == 0) {
                    if (zeroX == -1) {
                        zeroX = x;
                        zeroY = y;
                        //cout << "zeroX " << zeroX << " zeroY " << zeroY << endl;
                        zeroOutCol(matrix, x, true);
                        zeroOutRow(matrix, y, true);
                        matrix[x][y] = 0;
                    } else if (x != zeroX && y != zeroY) {
                        matrix[zeroX][y] = 1;
                        matrix[x][zeroY] = 1;
                    }
                }

        if (zeroX != -1) {
            for (int x = 0; x < matrix.size(); x++)
                if (matrix[x][zeroY])
                    zeroOutCol(matrix, x);
            for (int y = 0; y < matrix[0].size(); y++)
                if (matrix[zeroX][y])
                    zeroOutRow(matrix, y);
            zeroOutCol(matrix, zeroX);
            zeroOutRow(matrix, zeroY);
        }
    }
};
