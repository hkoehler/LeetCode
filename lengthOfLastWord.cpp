// https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        
        for (int pos = s.size() - 1; pos >= 0; pos--) {
            char c = s[pos];
            
            if (c != ' ')
                len++;
            else if(len > 0)
                return len;
        }

        return len;
    }
};
