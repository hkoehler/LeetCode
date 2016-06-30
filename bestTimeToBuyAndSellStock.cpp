// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum1 = 0, sum2 = 0, maxSum = 0;
        int last = 0;

        if (prices.empty())
            return 0;

        last = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            auto curr = prices[i];
            auto gain = curr - last;
            if (gain < 0)
                sum1 = 0;   // sell
            else
                sum1 += gain;
            sum2 += gain;
            if (sum1 > sum2)
                sum2 = sum1;
            maxSum = max(maxSum, sum2);
            last = curr;
        }
        return maxSum;
    }
};
