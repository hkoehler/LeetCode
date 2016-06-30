// https://leetcode.com/problems/interleaving-string/

// Using backtracking
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        while (!s3.empty()) {
            if (!s1.empty() && !s2.empty() && s1.back() == s2.back()) {
                auto ss1 = s1;
                auto ss2 = s2;
                s3.pop_back();
                ss1.pop_back();
                ss2.pop_back();
                return isInterleave(s1, ss2, s3) || isInterleave(ss1, s2, s3);
            }
            if (!s1.empty() && s1.back() == s3.back()) {
                s3.pop_back();
                s1.pop_back();
            } else if (!s2.empty() && s2.back() == s3.back()) {
                s3.pop_back();
                s2.pop_back();
            } else {
                return false;
            }
        }
        return s1.empty() && s2.empty() && s3.empty();
    }
};

// Dynamic programming solution
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        string ss3 = s3;
        string s;
        vector<pair<string, string>> prevState, state, nullState;
        
        prevState = {make_pair(s1, s2)};
        while (!s3.empty()) {
            char curr = s3.back();
            
            s3.pop_back();
            // look up previous solutions
            for (auto &sol : prevState) {
                auto &s1 = sol.first;
                auto &s2 = sol.second;
                
                // two potential solutions
                if (!s1.empty() && !s2.empty() && s1.back() == s2.back() && s1.back() == curr) {
                    auto ss1 = s1;
                    auto ss2 = s2;
                    
                    ss1.pop_back();
                    ss2.pop_back();
                    state.push_back(make_pair(ss1, s2));
                    state.push_back(make_pair(s1, ss2));
                // pop from s1
                } else if (!s1.empty() && s1.back() == curr) {
                    s1.pop_back();
                    state.push_back(make_pair(s1, s2));
                // pos from s2
                } else if (!s2.empty() && s2.back() == curr) {
                    s2.pop_back();
                    state.push_back(make_pair(s1, s2));
                }
            }
            prevState = state;
            state = nullState;
            cout << "state.size()=" << prevState.size() << endl;
        }
        for (auto sol : prevState) {
            if (sol.first.empty() && sol.second.empty())
                return true;
        }
        return false;
    }
};

// 2nd dynamic programming solution

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // indices are number of characters consumed
        // from either s1 or s2
        bool m[s1.size()+1][s2.size()+1];

        if (s1.size() + s2.size() != s3.size())
            return false;
        memset(m, 0, sizeof(m));
        // neither s1 nor s2 consumed
        m[0][0] = true;
        for (int i = 0; i <= s1.size(); i++)
            for (int j = 0; j <= s2.size(); j++) {
                size_t n = i + j;
                if (j > 0 && m[i][j-1] && s3[n-1] == s2[j-1])
                    m[i][j] = true;
                else if (i > 0 && m[i-1][j] && s3[n-1] == s1[i-1])
                    m[i][j] = true;
            }
        return m[s1.size()][s2.size()];
    }
};
