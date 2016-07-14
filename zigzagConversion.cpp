// https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> lines(numRows);
        string res;
        int pos = 0;
        
        if (numRows == 0)
            return s;
        while (pos < s.size()) {
            for (int i = 0; i < numRows && pos < s.size(); i++)
                lines[i].push_back(s[pos++]);
            for (int i = numRows - 2; i > 0 && pos < s.size(); i--)
                lines[i].push_back(s[pos++]);
        }
        for (auto line : lines)
            res.append(line);
        return res;
    }
};
