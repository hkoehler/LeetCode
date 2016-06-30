// https://leetcode.com/problems/decode-ways/
class Solution {
public:
    int numDecodings(string s) {
        map<string, int> m;
        
        if (s.empty())
            return 0;
        m[""] = 1;
        for (int i = 0; i < s.size(); i++) {
            int n = 0;
            auto s1 = s.substr(0, i);
            
            // single digit
            if (s[i] != '0')
                n = m[s1];
            // two digits (alternative way to decode)
            if (i > 0 && s[i-1] != '0' && ((s[i-1] == '2' && s[i] <= '6') || s[i-1] == '1')) {
                auto s2 = s.substr(0, i-1);
                n += m[s2];
            }
            m[s.substr(0, i+1)] = n;
        }
        return m[s];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        vector<int> m(s.size()+1);
        
        if (s.empty())
            return 0;
        m[0] = 1;
        // i: how many bytes consumed
        for (int i = 1; i <= s.size(); i++) {
            int n = 0, curr = s[i-1], prev = s[i-2];

            // single digit
            if (curr != '0')
                n = m[i-1];
            // two digits (alternative way to decode)
            if (i > 0 && prev != '0' && ((prev == '2' && curr <= '6') || prev == '1')) {
                n += m[i-2];
            }
            m[i] = n;
        }
        return m[s.size()];
    }
};

