//! https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int profit(vector<int> &diff, size_t begin, size_t end) {
        int res = 0;
        int sum = 0;
        
        for (int i = begin; i <= end; i++) {
            sum = max(0, sum + diff[i]);
            res = max(res, sum);
        }
        return res;
    }

    int maxProfit(vector<int>& prices) {
        vector<int> diff;
        int res = 0;

        // no chance to sell        
        if (prices.size() <= 1)
            return 0;
        
        // calculate difference
        for (int i = 1; i < prices.size(); i++)
            diff.push_back(prices[i] - prices[i-1]);

        // consider whole range first
        res = profit(diff, 0, diff.size() - 1);

        // divide into 2 ranges
        for (int i = 0; i < diff.size() - 1; i++)
            res = max(res, profit(diff, 0, i) + profit(diff, i+1, diff.size()-1));
        
        return res;
    }
};
