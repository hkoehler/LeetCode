// https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = numeric_limits<int>::max();
        int m2 = numeric_limits<int>::max();
        
        if (nums.size() < 3)
            return false;
        for (auto n : nums) {
            // first min candidate
            if (n <= m1)
                m1 = n;
            // 2nd min candiate > 1st min candidate
            else if (n <= m2)
                m2 = n;
            // n > 1st min and 2nd min
            else
                return true;
        }
        return false;
    }
};
