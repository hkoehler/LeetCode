//! https://leetcode.com/problems/reverse-vowels-of-a-string/

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        string vowels = "aeiouAEIOU";
        
        while (i < j) {
            if(find(vowels.begin(), vowels.end(), s[i]) == vowels.end()) {
                i++;
                continue;
            }
            if(find(vowels.begin(), vowels.end(), s[j]) == vowels.end()) {
                j--;
                continue;
            }
            swap(s[i], s[j]);
            i++; j--;
        }
        return s;
    }
};
