// https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> nums;
        
        while (n != 1) {
            int next = 0;
            
            while (n) {
                next += (n % 10) * (n % 10);
                n /= 10;
            }
            n = next;
            if (nums.find(n) != nums.end())
                return false;
            else
                nums.insert(n);
        }
        return true;
    }
};
