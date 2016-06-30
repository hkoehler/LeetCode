// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;

        int start = 0;
        int end = 0;
        int sum = nums[0];
        int min = INT_MAX;
        
        while (start < nums.size() && end < nums.size()) {
            //cout << "start " << start << " end " << end << " sum " << sum << endl;
            if (sum >= s)
                min = std::min(min, end - start + 1);
            if (sum <= s) {
                sum += nums[++end];
                continue;
            }
            if (sum >= s)
                sum -= nums[start++];
        }
        return min == INT_MAX ? 0 : min;
    }
};
