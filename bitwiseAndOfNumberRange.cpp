// https://leetcode.com/problems/bitwise-and-of-numbers-range/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = n;
        
        for (int i = 8 * sizeof(int) - 1; i >= 0; i--) {
            bool nBit = n & (1 << i);
            bool mBit = m & (1 << i);
            if (nBit != mBit)
                return n & ~((0x1 << (i + 1)) - 1);
        }
        return m;
    }
};
