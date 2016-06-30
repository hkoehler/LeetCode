class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<long long, vector<pair<int, int>>> m;
        
        if (nums.size() <= 1)
            return false;
        for (int i = 0; i < nums.size(); i++) {
            long long n = nums[i];
            long long b1 = (t == 0) ? n : n / t;
            long long b2 = b1 + 1;
            long long b3 = b1 - 1;
            
            for (auto &e : m[b1]) {
                if (abs(n - e.first) <= t && i - e.second <= k)
                    return true;
            }
            for (auto &e : m[b2]) {
                if (abs(n - e.first) <= t && i - e.second <= k)
                    return true;
            }
            for (auto &e : m[b3]) {
                if (abs(n - e.first) <= t && i - e.second <= k)
                    return true;
            }
            m[b1].push_back(make_pair(n, i));
        }
        
        return false;
    }
};
