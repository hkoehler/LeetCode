// https://leetcode.com/problems/count-numbers-with-unique-digits/

class Solution {
public:
    bool hasDigit(int n, int d) {
        while (n) {
            int t = n / 10;
            if (n - 10 * t == d)
                return true;
            n = t;
        }
        return false;
    }

    int countNumbersWithUniqueDigits(int n) {
        vector<int> nums;
        int res = 0;
        
        if (n == 0)
            return 0;
        for (int i = 0; i <= 9; i++)
            nums.push_back({i});
        res += nums.size();
        for (int i = 2; i <= n; i++) {
            vector<int> nextNums;
            
            for (auto num : nums)
                for (int d = 0; d <= 9; d++)
                    if (num != 0 && !hasDigit(num, d))
                        nextNums.push_back(10 * num + d);
            res += nextNums.size();
            nums = nextNums;
        }
        return res;
    }
};

class Solution {
public:
    int search(bitset<10> &digits, int n, int depth) {
        int count = 0;
        
        if (digits.count() > n)
            return 0;
        count++;
        for (int d = 0; d <= 9; d++) {
            // number cannot start with 0
            if (depth == 0 && d == 0)
                continue;
            if (digits[d] == false) {
                digits[d] = true;
                count += search(digits, n, depth+1);
                digits[d] = false;
            }
        }
        return count;
    }

    int countNumbersWithUniqueDigits(int n) {
        bitset<10> digits;
        return search(digits, n, 0);
    }
};

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int count = 0;
        if (n == 0)
            return 1;

        // calculate number of numbers with i digits
        for (int i = 1; i <= n; i++) {
            int c = 1;
            
            if (i == 1) {
                // digits 0 to 9
                c = 10;
            } else
                // first digit cannot be 0 
                for (int k = 1; k <= i; k++) {
                    if (k <= 2)
                        c *= 9;
                    else
                        // k digits are taken
                        c *= 10 - k + 1;
                }
            count += c;
        }
        return count;
    }
};
