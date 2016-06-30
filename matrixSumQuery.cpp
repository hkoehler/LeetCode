// https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
    size_t numRows, numCols;
    vector<vector<int>> m;
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        m = matrix;
        numRows = matrix.size();
        if (numRows == 0)
            return;
        numCols = matrix.back().size();

        dp.resize(numRows+1);
        for (int row = 0; row < numRows+1; row++)
            dp[row].resize(numCols+1);
        // sum up to (row, col)
        for (int row = 1; row <= numRows; row++)
            for (int col = 1; col <= numCols; col++)
                dp[row][col] = dp[row-1][col] + dp[row][col-1] + m[row-1][col-1] - dp[row-1][col-1];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (numRows == 0)
            return 0;
        return dp[row2+1][col2+1] - dp[row1][col2+1] - dp[row2+1][col1] + dp[row1][col1];
    }
};
