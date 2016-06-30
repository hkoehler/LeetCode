// n choose k permutations

class Solution {
public:
    vector<vector<int>> combinations;
    
    void solve(int k, int n, vector<int> nums) {
        if (k == 0)
            combinations.push_back(vector<int>(nums.begin(), nums.begin() + n));
        else
            for (int i = n; i < nums.size(); i++) {
                swap(nums[n], nums[i]);
                solve(k-1, n+1, nums);
                swap(nums[n], nums[i]);
            }
    }

    vector<vector<int>> permutate(int n, int k) {
        vector<int> nums;
        
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
        solve(k, 0, nums);
        return combinations;
    }
};

class Solution {
public:
    unordered_map<int, vector<vector<int>>> combinations;
    
    vector<vector<int>> combine(int n, int k) {
        for (int i = 1; i <= n; i++)
            combinations[1].push_back({i});
            
        for (int i = 2; i <= k; i++)
            for (auto comb : combinations[i-1])
                for (int num = 1; num <= n; num++)
                    if (find(comb.begin(), comb.end(), num) == comb.end()) {
                        auto newComb = comb;
                        newComb.push_back(num);
                        combinations[i].push_back(newComb);
                    }
        return combinations[k];
    }
};

// n choose k combinations
class Solution {
public:
    vector<vector<int>> combinations;

    // k: how many to choose
    // n: size of number space
    // p: current position in number space
    void solve(int k, int n, int p, vector<int> comb) {
        if (k == 0)
            combinations.push_back(comb);
        else
            for (int i = p; i <= n; i++) {
                comb.push_back(i);
                solve(k-1, n, i+1, comb);
                comb.pop_back();
            }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        
        solve(k, n, 1, comb);
        return combinations;
    }
};
