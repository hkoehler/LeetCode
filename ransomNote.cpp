// https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> counters(256);
        
        for (auto c : magazine)
            counters[c]++;
        for (auto c : ransomNote)
            if (counters[c]-- == 0)
                return false;
        return true;
    }
};
