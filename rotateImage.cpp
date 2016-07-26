// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // swap rows
        int i = 0, j = matrix.size() - 1;
        while (i < j)
            swap(matrix[i++], matrix[j--]);
        
        // mirrow diagonally
        for (int row = 0; row < matrix.size(); row++)
            for (int col = 0; col < row; col++)
                swap(matrix[row][col], matrix[col][row]);
    }
};
