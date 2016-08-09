// https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        int prev[2] = {1, 1};
        
        for (int i = 2; i <= n; i++) {
            int t = prev[0] + prev[1];
            prev[0] = prev[1];
            prev[1] = t;
        }
        return prev[1];
    }
};
