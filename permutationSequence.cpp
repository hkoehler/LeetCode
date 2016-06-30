// https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    size_t fac(size_t n) {
        int res = 1;
        for (int i = 2; i <= n; i++)
            res *= i;
        return res;
    }

    vector<int> solve(vector<int> nums, int k, vector<int> perm) {
        if (nums.empty())
            return perm;
        // calculate next element to be chosen based on k
        int next = k / fac(nums.size()-1);
        perm.push_back(nums[next]);
        // remove next element from set
        vector<int> nextNums;
        for (int i = 0; i < nums.size(); i++)
            if (i != next)
                nextNums.push_back(nums[i]);
        // solve for subset
        return solve(nextNums, k - (next * fac(nums.size()-1)), perm);
    }

    string getPermutation(int n, int k) {
        vector<int> nums;
        string res;
        
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
        nums = solve(nums, (k-1) % fac(n), {});
        for (auto n : nums) 
            res.push_back(0x30+n);
        return res;
    }
};
