class Solution {
public:
    int target;
    int curr;
    bool currValid = false;
    
    void solve(vector<int> s, vector<int> nums) {
        if (s.size() == 3) {
            int sum = 0;
            for (auto n : s)
                sum += n;
            if (!currValid || abs(sum - curr) < abs(target - curr))
                curr = sum;
            return;
        }
        
        while (!nums.empty()) {
            auto n = nums.back();
            nums.pop_back();
            auto newS = s;
            newS.push_back(n);
            solve(newS, nums);
        }
    }

    int threeSumClosest(vector<int>& nums, int target) {
        this->target = target;
        solve({}, nums);
        return curr;
    }
};

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int curr;
        bool currValid = false;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                for (int k = 0; k < nums.size(); k++) {
                    if (i != j && j != k && i != k) {
                        int sum = nums[i] + nums[j] + nums[k];
                        if (!currValid || abs(sum - target) < abs(curr - target)) {
                            curr = sum;
                            currValid = true;
                        }
                    }
                }
            }
        }
        return curr;
    }
};

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int result = nums[0] + nums[1] + nums[2];
        int diff = abs(target-result);
        
        for (int i = 0; i < nums.size(); i++) {
            int j = i+1;
            int k = nums.size() - 1;

            while (j < k) {
                auto sum = nums[i] + nums[j] + nums[k];
                
                if (abs(target-sum) < diff) {
                    result = sum;
                    diff = abs(target-sum);
                }
                if (sum > target)
                    k--;
                else if (sum < target)
                    j++;
                else
                    return target;
            }
        }
        
        return result;
    }
};

