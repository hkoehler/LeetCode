// https://leetcode.com/problems/combination-sum-iii/
class Solution {
public:
    vector<vector<int>> results;
    vector<int> numSet;
    
    void solve(size_t pos, int k, int n, vector<int> nums) {
        // base case
        if (k == 0 && n == 0) {
            results.push_back(nums);
        } else if (k == 0)
            return;
        for (size_t i = pos; i < numSet.size(); i++) {
            if (numSet[i] <= n) {
                nums.push_back(numSet[i]);
                solve(i+1, k-1, n-numSet[i], nums);
                nums.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        for (int i = 1; i <= 9; i++)
            numSet.push_back(i);
        solve(0, k, n, {});
        return results;
    }
};
