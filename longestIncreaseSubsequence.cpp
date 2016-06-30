// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxSize = 1;
        vector<int> m(nums.size());
        
        if (nums.size() < 2)
            return nums.size();
        // initially there are only subranges of size 1
        for (int i = 0; i < nums.size(); i++)
            m[i] = 1;
        // merge subranges
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    m[i] = max(m[i], m[j]+1);
                    maxSize = max(maxSize, m[i]);
                }
            }
        }
        return maxSize;
    }
};
