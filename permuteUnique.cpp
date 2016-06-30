class Solution {
public:
    vector<vector<int>> permutations;
    
    void solve(const vector<int> &prefix, const vector<int> &nums) {
        set<int> dups;
        
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            
            if (dups.find(n) == dups.end()) {
                dups.insert(n);
                auto nextNums = nums;
                auto nextPrefix = prefix;
                nextPrefix.push_back(n);
                nextNums.erase(nextNums.begin()+i);
                if (nextNums.empty())
                    permutations.push_back(nextPrefix);
                else
                    solve(nextPrefix, nextNums);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> prefix;
        
        if (nums.size() == 0 || nums.size() == 1)
            return {nums};
        solve(prefix, nums);
        return permutations;
    }
};
