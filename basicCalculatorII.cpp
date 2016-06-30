// https://leetcode.com/problems/basic-calculator-ii/

class Solution {
public:
    int calculate(string s) {
        int last = 0;
        int product = 0;
        int res = 0;
        char mode = '+';
        vector<string> eq;
        vector<char> operators = {'+', '-', '*', '/'};

        string curr;
        for (auto &c: s) {
            if (c == ' ')
                continue;
            if (find(operators.begin(), operators.end(), c) == operators.end())
                curr.push_back(c);
            else {
                eq.push_back(curr);
                curr = "";
                eq.push_back({c});
            }
        }
        eq.push_back(curr);
        
        for (auto &c : eq) {
            //cout << c << endl;
            switch (c[0]) {
            case '+':
            case '-':
                res += product + last;
                product = last = 0;
                mode = c[0];
                break;
            case '*':
            case '/':
                if (mode == '+' || mode == '-') {
                    product = last;
                    last = 0;
                }
                mode = c[0];
                break;
            default:
                int n = atoi(c.c_str());
                switch (mode) {
                case '+':
                    last = n;
                    break;
                case '-':
                    last = -n;
                    break;
                case '*':
                    product *= n;
                    break;
                case '/':
                    product /= n;
                    break;
                }
            }
        }
        res += product + last;

        return res;
    }
};
