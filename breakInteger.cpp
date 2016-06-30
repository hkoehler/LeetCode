// https://leetcode.com/problems/integer-break/

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            // split i
            for (int j = 1; j < i; j++) {
                //cout << i << " = " << j << " + " << i - j << endl;
                if (dp[j] * dp[i-j] > dp[i])
                    dp[i] = dp[j] * dp[i-j];
                if (j * dp[i-j] > dp[i])
                    dp[i] = j * dp[i-j];
                if (j * (i-j) > dp[i])
                    dp[i] = j * (i - j);
            }
            //cout << i << " " << dp[i] << endl;
        }
        return dp[n];
    }
};
