class Solution {
public:
    int lowerBound(vector<int> &nums, int target, int lo, int hi) {
        while (lo < hi) {
            int m = lo + (hi - lo) / 2; // favor 1st value in [n, n]
            // lower-bound is first element >= target
            if (nums[m] >= target)
                hi = m; // exclude all elements after m
            else
                lo = m + 1; // exclude elements < target
        }
        if (nums[lo] == target)
            return lo;
        else
            return -1;
    }

    int upperBound(vector<int> &nums, int target, int lo, int hi) {
        while (lo < hi) {
            int m = lo + (hi - lo + 1) / 2; // favor 2nd value in [n, n]
            if (nums[m] > target) // exclude all elements after and including m
                hi = m - 1;
            else
                lo = m; // exclude elements before m (nums[lo] <= target)
        }
        if (nums[lo] == target)
            return lo;
        else
            return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int lo, hi;

        lo = lowerBound(nums, target, 0, nums.size() - 1);
        hi = upperBound(nums, target, 0, nums.size() - 1);
        return {lo, hi};
    }
};
