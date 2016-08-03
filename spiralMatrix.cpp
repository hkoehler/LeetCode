// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        if (matrix.empty())
            return {};
        
        int lastCol = matrix.back().size() - 1;
        int lastRow = matrix.size() - 1;

        for (int i = 0; 2 * i <= lastCol && 2 * i <= lastRow; i++) {
            for (int col = i; col <= lastCol - i; col++)
                res.push_back(matrix[i][col]);
            for (int row = i+1; row <= lastRow - i - 1; row++)
                res.push_back(matrix[row][lastCol-i]);
            if (lastRow - i != i)
                for (int col = lastCol - i; col >= i; col--)
                    res.push_back(matrix[lastRow - i][col]);
            if (lastCol - i != i)
                for (int row = lastRow - i - 1; row >= i+1; row--)
                    res.push_back(matrix[row][i]);
        }
        return res;
    }
};
