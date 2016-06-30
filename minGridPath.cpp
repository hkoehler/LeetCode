// https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        
        size_t height = grid.size();
        size_t width = grid[0].size();
        vector<vector<int>> dp(height+1);
        
        for (auto &row : dp)
            row.resize(width+1, INT_MAX);
        
        dp[1][1] = grid[0][0];
        for (int row = 1; row <= height; row++)
            for (int col = 1; col <= width; col++)
                if (row != 1 || col != 1)
                    dp[row][col] = min(dp[row-1][col], dp[row][col-1]) + grid[row-1][col-1];
        return dp[height][width];
    }
};
