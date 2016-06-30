class Solution {
public:
    int robInt(vector<int>& nums, vector<bool> &robbed) {
        vector<int> sum;
        
        sum.resize(nums.size());
        robbed.resize(nums.size());
        
        if (nums.empty())
            return 0;
        else if (nums.size() == 1)
            return nums.back();
        
        for (int i = 0; i < nums.size(); i++)
            if (i == 0)
                sum[i] = nums[i];
            else if (i == 1)
                sum[i] = max(nums[i], nums[i-1]);
            else {
                if (sum[i-1] > nums[i] + sum[i-2]) {
                    sum[i] = sum[i-1];
                    robbed[i] = false;
                    robbed[i-1] = true;
                    robbed[i-2] = false;
                } else {
                    sum[i] = nums[i] + sum[i-2];
                    robbed[i] = true;
                    robbed[i-1] = false;
                    robbed[i-2] = true;
                }
            }
        return sum.back();
    }

    int rob(vector<int>& nums) {
        vector<bool> robbed;
        
        if (nums.empty())
            return 0;
        else if (nums.size() == 1)
            return nums.back();
        
        int sum = robInt(nums, robbed);
        
        if (robbed.front() && robbed.back()) {
            vector<int> nums1;
            vector<bool> robbed1;
            
            nums1.insert(nums1.begin(), nums.begin()+1, nums.end());
            int sum1 = robInt(nums1, robbed1);
            
            vector<int> nums2;
            vector<bool> robbed2;
            
            nums2.insert(nums2.begin(), nums.begin(), nums.end()-1);
            int sum2 = robInt(nums2, robbed2);
            
            return max(sum1, sum2);
        }
        return sum;
    }
};rps6dw

