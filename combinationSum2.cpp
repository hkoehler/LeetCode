class Solution {
public:
    vector<vector<int>> combs;

    void solve(vector<int>& candidates, int target, int pos, vector<int> comb) {
        int prev;
        
        for (int i = pos; i < candidates.size(); i++) {
            int n = candidates[i];

            if (i > pos && prev == n)
                continue;
            comb.push_back(n);
            if (target == n)
                combs.push_back(comb);
            else if (target > n)
                solve(candidates, target-n, i+1, comb);
            comb.pop_back();
            prev = n;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, {});
        return combs;
    }
};
