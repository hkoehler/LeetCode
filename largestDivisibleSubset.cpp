// https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> dp(nums.size());
        vector<vector<int>> subRes(nums.size());
        vector<int> res;
        int maxSubset = 0;
        
        if (nums.size() <= 1)
            return nums;
        
        sort(nums.begin(), nums.end());
        dp[0] = 1;
        subRes[0] = {nums[0]};
        res = subRes[0];
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = 1;
            subRes[i] = {nums[i]};
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    subRes[i] = subRes[j];
                    subRes[i].push_back(nums[i]);
                }
            }
            if (dp[i] > maxSubset) {
                maxSubset = max(maxSubset, dp[i]);
                res = subRes[i];
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // each element is its own subset
        vector<int> dp(nums.size(), 1);
        int maxSubset = 0;
        
        if (nums.size() <= 1)
            return nums;
        
        sort(nums.begin(), nums.end());
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j < i; j++)
                if (nums[i] % nums[j] == 0)
                    dp[i] = max(dp[i], dp[j] + 1);
            maxSubset = max(maxSubset, dp[i]);
        }

        // reconstruct result
        vector<int> res;
        for (int i = dp.size() - 1; i >= 0; i--)
            if (res.empty()) {
                if (dp[i] == maxSubset)
                    res.push_back(nums[i]);
            } else if (res.back() % nums[i] == 0)
                res.push_back(nums[i]);
        
        for (int i = 0, j = res.size() - 1; i < j;)
            swap(res[i++], res[j--]);
        
        return res;
    }
};
