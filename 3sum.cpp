// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        int last;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int j = i+1;
            int k = nums.size() - 1;

            // skip duplicates
            if (i > 0 && last == nums[i])
                continue;
            else
                last = nums[i];
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] > 0)
                    k--;
                else if (nums[i] + nums[j] + nums[k] < 0)
                    j++;
                else {
                    results.push_back({nums[i], nums[j], nums[k]});
                    // skip duplicates
                    while (nums[i] + nums[j] + nums[k] == 0 && k >= 0)
                        k--;
                    while (nums[i] + nums[j] + nums[k] == 0 && j < nums.size())
                        j++;
                }
            }
       }
       return results;
    }
};

