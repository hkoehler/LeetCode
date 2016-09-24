// https://leetcode.com/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty())
            return false;
        vector<bool> dp(s.size() + 1);
        
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            if (dp[i-1] == false)
                continue;
            for (auto &w : wordDict) {
                if (s.compare(i-1, w.size(), w) == 0)
                    dp[i - 1 + w.size()] = true;
            }
        }
        return dp[s.size()];
    }
};
