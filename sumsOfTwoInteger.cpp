// https://leetcode.com/problems/sum-of-two-integers/

class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            // calculate sum w/o carry
            int sum = a ^ b;
            // calculate carry bit ignoring sum
            int carry = a & b;
            // let a be sum w/o carry
            a = sum;
            // let b be carry bits
            b = carry << 1;
        }
        return a;
    }
};
