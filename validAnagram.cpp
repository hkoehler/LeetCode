// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> chars;
        
        if (s.size() != t.size())
            return false;
        
        for (auto c : t)
            chars[c]++;
        
        for (auto c : s)
            if (chars[c]-- == 0)
                return false;

        for (auto &p : chars)
            if (p.second > 0)
                return false;
        return true;
    }
};
