// https://leetcode.com/problems/different-ways-to-add-parentheses/

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        size_t splits = 0;
        
        // divide string by operators
        for (int pos = 0; pos < input.size(); pos++) {
            char op = input[pos];
            if (op == '+' || op == '-' || op == '*') {
                splits++;
                auto res1 = diffWaysToCompute(input.substr(0, pos));
                auto res2 = diffWaysToCompute(input.substr(pos+1));
                for (auto n1 : res1)
                    for (auto n2 : res2)
                        if (input[pos] == '+')
                            res.push_back(n1 + n2);
                        else if (input[pos] == '-')
                            res.push_back(n1 - n2);
                        else
                            res.push_back(n1 * n2);
            }
        }
        if (splits == 0)
            res.push_back(atoi(input.c_str()));
        sort(res.begin(), res.end());
        return res;
    }
};
