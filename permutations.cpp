class Solution {
public:
    vector<vector<int>> permutations;
    
    void solve(vector<int> &prefix, vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            auto nextNums = nums;
            auto nextPrefix = prefix;
            auto n = nums[i];
            
            nextNums.erase(nextNums.begin() + i);
            nextPrefix.push_back(n);
            if (nextNums.empty())
                permutations.push_back(nextPrefix);
            else
                solve(nextPrefix, nextNums);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> prefix;
        
        if (nums.empty())
            return {{}};
        solve(prefix, nums);
        return permutations;
    }
};

class Solution {
public:
    vector<vector<int>> permutations;
    
    void solve(int k, vector<int> nums) {
        assert(k <= nums.size());
        if (k == nums.size())
            permutations.push_back(nums);
        else
            for (int i = k; i < nums.size(); i++) {
                swap(nums[i], nums[k]);
                solve(k+1, nums);
                swap(nums[i], nums[k]);
            }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() <= 1)
            return {nums};
        solve(0, nums);
        return permutations;
    }
};
