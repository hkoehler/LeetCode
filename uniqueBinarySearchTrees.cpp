// https://leetcode.com/problems/unique-binary-search-trees/


// top-down
class Solution {
public:
    unordered_map<int, int> cache;

    int numTrees(int n) {
        int sum = 0;
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        auto prev = cache.find(n);
        if (prev != cache.end())
            return prev->second;
        // choose root n ways
        for(int i = 0; i < n; i++) {
            int left = numTrees(i);
            int right = numTrees(n - i - 1);
            if (left == 0)
                left = 1;
            if (right == 0)
                right = 1;
            sum += left * right;
        }
        cache[n] = sum;
        return sum;
    }
};

// bottom-up
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        
        dp[0] = 1;
        for (int curr = 1; curr <= n; curr++) {
            int sum = 0;
            
            // choose root n ways
            for(int i = 0; i < curr; i++) {
                int left = dp[i];
                int right = dp[curr - i - 1];
                if (left == 0)
                    left = 1;
                if (right == 0)
                    right = 1;
                sum += left * right;
            }
            dp[curr] = sum;
        }
        return dp[n];
    }
};
