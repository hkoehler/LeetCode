// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        long tmp = x;
        long reverse = 0;
        
        if (x < 0)
            return false;
        while (tmp != 0) {
            int digit = tmp % 10;
            tmp /= 10;
            reverse *= 10;
            reverse += digit;
        }
        
        return reverse == x;
    }
};
