// https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty())
            return 0;
        if (obstacleGrid.back().empty())
            return 0;
        if (obstacleGrid[0][0] == 1)
            return 0;
        
        size_t m = obstacleGrid.size();
        size_t n = obstacleGrid.back().size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));

        for (int x = 1; x <= m; x++)
            for (int y = 1; y <= n; y++)
                if (x == 1 && y == 1)
                    dp[x][y] = 1;
                else if (obstacleGrid[x-1][y-1])
                    dp[x][y] = 0;
                else
                    dp[x][y] = dp[x-1][y] + dp[x][y-1];
        return dp[m][n];
    }
};
