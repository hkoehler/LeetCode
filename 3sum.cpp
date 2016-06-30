class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> posNums;
        vector<int> negNums;
        map<int, vector<pair<int, int>>> posPairs;
        map<int, vector<pair<int, int>>> negPairs;

        for (auto n : nums)
            if (n >= 0)
                posNums.push_back(n);
            else
                negNums.push_back(n);
        if (posNums.empty())
            return results;
        if (negNums.empty())
            return results;
        sort(posNums.begin(), posNums.end());
        sort(negNums.begin(), negNums.end());
        
        for (int i = 0; i < posNums.size(); i++)
            for (int j = i+1; j < posNums.size(); j++)
                posPairs[posNums[i] + posNums[j]].push_back({posNums[i], posNums[j]});
        for (int i = 0; i < negNums.size(); i++)
            for (int j = i+1; j < negNums.size(); j++)
                negPairs[posNums[i] + posNums[j]].push_back({posNums[i], posNums[j]});
        for (auto n : posNums) {
            auto negPair = negPairs.find(-n);
            if (negPair != negPairs.end()) {
                for (auto p : negPair->second) {
                    vector<int> res;
                    res.push_back(p.first);
                    res.push_back(p.second);
                    res.push_back(n);
                    results.push_back(res);
                }
            }
        }
        for (auto n : negNums) {
            auto posPair = posPairs.find(-n);
            if (posPair != posPairs.end()) {
                for (auto p : posPair->second) {
                    vector<int> res;
                    res.push_back(n);
                    res.push_back(p.first);
                    res.push_back(p.second);
                    results.push_back(res);
                }
            }
        }
        return results;
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int j = i+1;
            int k = nums.size() - 1;

            while (j < k) {
                if (nums[i] + nums[j] + nums[k] > 0)
                    k--;
                else if (nums[i] + nums[j] + nums[k] < 0)
                    j++;
                else {
                    results.push_back({nums[i], nums[j], nums[k]});
                    k--;
                    j++;
                }
            }
       }
        
        return results;
    }
};


