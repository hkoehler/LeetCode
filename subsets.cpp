// subset with duplicates

class Solution {
public:
    set<vector<int>> subsets;

    void solve(vector<int> subset, vector<int> nums) {
        while (!nums.empty()) {
            auto n = nums.back();
            nums.pop_back();
            auto newSubset = subset;
            newSubset.push_back(n);
            subsets.insert(newSubset);
            solve(newSubset, nums);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        
        sort(nums.begin(), nums.end(), std::greater<int>());
        solve({}, nums);
        ret.push_back({});
        for (auto subset : subsets) {
            ret.push_back(subset);
        }
        return ret;
    }
};
