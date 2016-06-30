class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        vector<string> operators = {"+", "-", "*", "/"};
        
        for (auto &token : tokens) {
            int op1, op2;
            
            if (find(operators.begin(), operators.end(), token) != operators.end()) {
                op2 = s.top();
                s.pop();
                op1 = s.top();
                s.pop();
            }
            if (token == "+")
                s.push(op1+op2);
            else if (token == "-")
                s.push(op1-op2);
            else if (token == "*")
                s.push(op1*op2);
            else if (token == "/")
                s.push(op1/op2);
            else
                s.push(atoi(token.c_str()));
        }
        return s.top();
    }
};
