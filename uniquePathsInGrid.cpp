// https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
        
        memset(dp, 0, sizeof(dp));
        for (int x = 1; x <= m; x++)
            for (int y = 1; y <= n; y++)
                if (x == 1 && y == 1)
                    dp[x][y] = 1;
                else
                    dp[x][y] = dp[x-1][y] + dp[x][y-1];
        return dp[m][n];
    }
};
