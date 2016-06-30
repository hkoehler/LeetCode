// https://leetcode.com/problems/search-insert-position/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        
        while (lo < hi) {
            int m = lo + (hi - lo) / 2;
            if (nums[m] >= target)
                hi = m;
            else
                lo = m + 1;
        }
        return lo;
    }
};
