// https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n));
        
        int beginCol = 0;
        int endCol = n - 1;
        int beginRow = 0;
        int endRow = n - 1;
        int num = 1;
        
        while (beginRow <= endRow && beginCol <= endCol) {
            for (int col = beginCol; col <= endCol; col++)
                m[beginRow][col] = num++;
            beginRow++;
            
            for (int row = beginRow; row <= endRow; row++)
                m[row][endCol] = num++;
            endCol--;
            
            for (int col = endCol; col >= beginCol; col--)
                m[endRow][col] = num++;
            endRow--;
            
            for (int row = endRow; row >= beginRow; row--)
                m[row][beginCol] = num++;
            beginCol++;
        }
        
        return m;
    }
};
