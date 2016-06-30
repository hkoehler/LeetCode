// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string str) {
        long n = 0;
        bool negative = false;
        auto c = str.begin();
        
        while (c != str.end() && isspace(*c))
            c++;
        if (c == str.end())
            return 0;
        if (*c == '-') {
            negative = true;
            c++;
        } else if (*c == '+') {
            negative = false;
            c++;
        }
        while (c != str.end() && isdigit(*c)) {
            n *= 10;
            if (negative)
                n -= *c - 0x30;
            else
                n += *c - 0x30;
            if (n > INT_MAX)
                return INT_MAX;
            if (n < INT_MIN)
                return INT_MIN;
            //cout << n << endl;
            c++;
        }
        return n;
    }
};
