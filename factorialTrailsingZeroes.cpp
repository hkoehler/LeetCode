// https://leetcode.com/problems/factorial-trailing-zeroes/

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        // only 2 * 5 can produce 10
        while (n) {
            int t = n / 5;
            res += t;
            n = t;
        }
        return res;
    }
};
