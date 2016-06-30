https://leetcode.com/problems/product-of-array-except-self/

// product = left product + right product
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int multiplier;
        
        if (nums.empty())
                return res;
        res[0] = 1;
        for (int i = 1; i < nums.size(); i++)
            res[i] = res[i-1] * nums[i-1];
        multiplier = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            multiplier *= nums[i+1];
            res[i] = res[i] * multiplier;
        }
        return res;
    }
};
