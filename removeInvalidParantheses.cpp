// https://leetcode.com/problems/remove-invalid-parentheses/

class Solution {
public:
    int order(const std::string &s, bool &negative) {
        int n = 0;
        
        negative = false;
        for (auto c : s) {
            if (c == '(')
                n++;
            else if (c == ')') {
                if (--n < 0)
                    negative = true;
            }
        }
        return n;
    }
    
    void reverse(std::string &s) {
        if (s.empty())
            return;
        
        size_t lo = 0;
        size_t hi = s.size() - 1;
        
        for (auto &c : s) {
            switch (c) {
            case '(':
                c = ')';
                break;
            case ')':
                c = '(';
                break;
            default:
                break;
            }
        }
        while (lo < hi) {
            swap(s[lo++], s[hi--]);
        }
    }
    
    string removeParantheses(string &s) {
        string res;
        for (auto &c : s)
            if (c != '(' && c != ')')
                res.push_back(c);
        return res;
    }

    void solve(string s, size_t pos, size_t depth, set<string> &res) {
        bool neg;
        
        auto o = order(s, neg);
        if (o == 0) {
            if(neg == false)
                res.insert(s);
            return;
        }
        if (depth == 0)
            return;

        //cout << "s=" << s << " pos=" << pos << " depth=" << depth << endl;
        for (int i = pos; i < s.size(); i++) {
            if (s[i] == '(') {
                string tmp = s;
                tmp.erase(i, 1);
                solve(tmp, i, depth-1, res);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        bool rev = false;
        set<string> res;
        vector<string> res2;
        int depth;
        bool negative;
        
        depth = order(s, negative);
        //cout << "order " << depth << endl;
        if (depth < 0) {
            rev = true;
            reverse(s);
            depth = -depth;
        }
        //cout << s << endl;
        solve(s, 0, depth, res);
        // no valid solution found
        if (res.empty())
            res.insert(removeParantheses(s));
        
        for (auto s : res) {
            if (rev)
                reverse(s);
            res2.push_back(s);
        }
        return res2;
    }
};
