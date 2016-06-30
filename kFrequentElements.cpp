// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // map values to counter
        unordered_map<int, int> counters;
        vector<vector<int>> buckets(nums.size()+1);
        vector<int> res;

        // count frequency of elements
        for (auto n : nums)
            counters[n]++;
        // bucket sort by counter value
        for (auto c : counters)
            buckets[c.second].push_back(c.first);
        // collect numbers starting with highest frequency (counter value)
        for (auto b = buckets.rbegin(); b != buckets.rend(); b++) {
            res.insert(res.begin(), b->begin(), b->end());
            if (res.size() >= k)
                break;
        }
        sort(res.begin(), res.end());
        return res;
    }
};
