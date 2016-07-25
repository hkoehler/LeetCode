// https://leetcode.com/problems/regular-expression-matching/

class Solution {
public:
    // dissect regex
    // wildcard: true if char followed by *
    // return: either a-z, A-Z or .
    bool getExpr(string p, size_t &pos, char &c, bool &wildcard) {
        if (pos == p.size())
            return false;
            
        c = p[pos++];
        // check for wildcard
        wildcard = false;
        if (pos < p.size() && p[pos] == '*') {
            wildcard = true;
            pos++;
        }
        return true;
    }
    
    bool isMatch(string s, string p) {
        size_t regexPos = 0;
        char c;
        bool wildcard;
        vector<bool> state(s.size()+1);
        
        state[0] = true;
        while (getExpr(p, regexPos, c, wildcard)) {
            // number of characters consumed
            vector<bool> nextState(s.size()+1);
            
            for (int pos = 0; pos <= s.size(); pos++) {
                if (state[pos] == false)
                    continue;
                if (wildcard) {
                    // match zero characters
                    nextState[pos] = true;
                    // match > 0 characters
                    for (int n = 0; pos + n < s.size(); n++)
                        if (c == '.' || c == s[pos + n])
                            nextState[pos + n + 1] = true;
                        else
                            break;
                } else if (pos < s.size() && (c == '.' || c == s[pos]))
                    nextState[pos + 1] = true;
            }
            state = nextState;
        }
        
        return state[s.size()];
    }
};
