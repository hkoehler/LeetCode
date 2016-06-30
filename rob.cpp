class Solution {
public:
    int rob(vector<int>& nums, int pos) {
        int sum = 0;

        for (int i = pos+2; i < nums.size(); i++) {
            int s = rob(nums, i);
            if (s > sum)
                sum = s;
        }
        sum += nums[pos];
        return sum;
    }

    int rob(vector<int>& nums) {
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int s = rob(nums, i);
            if (s > sum)
                sum = s;
        }
        return sum;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int sum1 = 0, sum2 = 0;

        for (int i = 0; i < nums.size(); i++)
            if (i % 2 == 0)
                sum1 = max(sum1 + nums[i], sum2);
            else
                sum2 = max(sum2 + nums[i], sum1);
        return max(sum1, sum2);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> sum(nums.size());
        
        for (int i = 0; i < nums.size(); i++)
            if (i == 0)
                sum[i] = nums[i];
            else if (i == 1)
                sum[i] = max(nums[i], nums[i-1]);
            else
                sum[i] = max(sum[i-1], nums[i] + sum[i-2]);
        return sum.empty() ? 0 : sum.back();
    }
};
