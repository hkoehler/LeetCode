// https://leetcode.com/problems/subsets/

class Solution {
    vector<vector<int>> res;
public:
    void choose(vector<int>& nums, size_t pos, size_t n, vector<int> set) {
        if (n == 0)
            res.push_back(set);
        for (int i = pos; i < nums.size(); i++) {
            set.push_back(nums[i]);
            choose(nums, i+1, n-1, set);
            set.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        for (int i = 0; i <= nums.size(); i++)
            choose(nums, 0, i, {});
        return res;
    }
};
