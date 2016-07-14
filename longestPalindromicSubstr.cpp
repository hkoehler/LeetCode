// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    
    string check(string s, int i, int start, int off, int max) {
        int len = start;
        string res;
        
        if (len)
            res = s[i];
        for (int j = start; j + i + off < s.size() && i-j >= 0 ; j++) {
            if (s[i+j+off] == s[i-j])
                len += 2;
            else
                break;
            if (len > max)
                res = s.substr(i-j, len);
        }
        return res;
    }    

    string longestPalindrome(string s) {
        int max = 0;
        string res;
        
        if (s.empty())
            return res;
        for (int i = 0; i < s.size(); i++) {
            // check for odd palindrome
            auto s1 = check(s, i, 1, 0, max);
            // check for even palindrome
            auto s2 = check(s, i, 0, 1, max);
            auto &s3 = s1.size() > s2.size() ? s1 : s2;
            if (s3.size() > max) {
                max = s3.size();
                res = s3;
            }
        }
        return res;
    }
};
