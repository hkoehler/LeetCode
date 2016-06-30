// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> diff;

        // no chance to sell        
        if (prices.size() <= 1)
            return 0;
        
        // calculate difference
        for (int i = 1; i < prices.size(); i++) {
            diff.push_back(prices[i] - prices[i-1]);
            //cout << diff.back() << endl;
        }
        
        // find max subsequence
        vector<int> dp(diff.size());
        dp[0] = diff[0];
        for (int i = 1; i < diff.size(); i++)
            dp[i] = max(diff[i], max(dp[i-1] + diff[i], dp[i-1]));
        return max(dp[diff.size() - 1], 0);
    }
};
