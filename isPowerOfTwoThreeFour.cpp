// https://leetcode.com/problems/power-of-three/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1)
            return false;
        return (n & (n - 1)) == 0;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1)
            return false;
        while (n != 1) {
            if (n % 3)
                return false;
            else
                n /= 3;
        }
        return true;
    }
};

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num < 1)
            return false;
        // is power of 2?
        if (num & (num - 1))
            return false;
        /*while (num != 1) {
            if (num & 0x3)
                return false;
            num >>= 0x2;
        }*/
        return num & 0x55555555;
    }
};
