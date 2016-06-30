class Solution {
public:

    vector<vector<int>> combinations;
    
    void solve(vector<int>& candidates, int target, int pos, vector<int> comb) {
        if (target == 0) {
            combinations.push_back(comb);
            return;
        }
        for (int i = pos; i < candidates.size(); i++) {
            int n = candidates[i];
            
            if (target >= n) {
                comb.push_back(candidates[i]);
                solve(candidates, target-n, i, comb);
                comb.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, {});
        return combinations;
    }
};
