// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums, int begin, int end) {
        if (nums[begin] <= nums[end])
            return nums[begin];
        size_t m = begin + (end - begin) / 2;
        return min(findMin(nums, begin, m), findMin(nums, m+1, end));
    }

    int findMin(vector<int>& nums) {
        if (nums.empty())
            return 0;
        return findMin(nums, 0, nums.size() - 1);
    }
};
