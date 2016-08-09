//! https://leetcode.com/problems/coin-change/

// [442,295,365,485]
// 8091

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        unordered_set<int> c;
        
        dp[0] = 0;
        for (auto coin : coins)
            c.insert(coin);
        
        for (int i = 1; i <= amount; i++)
            if (c.find(i) != c.end())
                dp[i] = 1;
            else
                for (int k = 1; k < i; k++)
                    if (dp[i-k] != INT_MAX && dp[k] != INT_MAX)
                        dp[i] = min(dp[i], dp[i-k] + dp[k]);
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

// accepted solution

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount+1);

        dp[0] = 0;
        for (int curr = 1; curr <= amount; curr++)
            for (auto coin : coins)
                if (coin <= curr)
                    dp[curr] = min(dp[curr], dp[curr - coin] + 1);
        return dp[amount] == (amount + 1) ? -1 : dp[amount];
    }
};
