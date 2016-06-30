// https://leetcode.com/problems/basic-calculator/

class Solution {
public:

    struct SubResult
    {
        SubResult() : op('+'), sum(0) {}
        void reset() {
            op = '+';
            sum = 0;
        }
        char op;    // + or -
        int sum;
    };
    
    int calculate(string s) {
        std::stack<SubResult> stack;
        SubResult curr;
        string currNumStr;
        int currNum;

        s.push_back('=');
        for (auto c : s) {
            if (c == ')' || c == '+' || c == '-' || c == '=') {
                currNum = atoi(currNumStr.c_str());
                currNumStr = "";
                if (curr.op == '+')
                    curr.sum += currNum;
                else
                    curr.sum -= currNum;
            }
            if (c == '(') {
                stack.push(curr);
                curr.reset();
            } else if (c == ')') {
                auto prev = stack.top();
                stack.pop();
                if (prev.op == '+')
                    curr.sum = prev.sum + curr.sum;
                else
                    curr.sum = prev.sum - curr.sum;
                curr.op = prev.op;
            } else if (c == '+') {
                curr.op = c;
            } else if (c == '-') {
                curr.op = c;
            } else if (c == ' ')
                continue;
            else {
                currNumStr.push_back(c);
            }
         }
         return curr.sum;
    }
};
