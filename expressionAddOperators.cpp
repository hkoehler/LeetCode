// https://leetcode.com/problems/expression-add-operators/ (282)

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        
        for (int i = num.size() - 1; i >= 0; i--) {
            // divided num from the back
            string currNum = num.substr(i);
            stringstream ss(currNum);
            int curr;
            
            ss >> curr;
            // remaining numbers from the front
            string remNum = num.substr(0, num.size()-i);
            if (remNum.empty()) {
                if (target == curr)
                    res.push_back(currNum);
                break;
            }
            if (curr != 0 && target % curr == 0) {
                auto tmp = addOperators(remNum, target / curr);
                for (auto s : tmp) {
                    stringstream ss;
                    ss << s << "*" << curr;
                    res.push_back(ss.str());
                }
            }
            auto tmp = addOperators(remNum, target - curr);
            for (auto s : tmp) {
                stringstream ss;
                ss << s << "+" << curr;
                res.push_back(ss.str());
            }
            tmp = addOperators(remNum, target + curr);
            for (auto s : tmp) {
                stringstream ss;
                ss << s << "-" << curr;
                res.push_back(ss.str());
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<string> results;

    void addOperators(string num, size_t pos, int target, int productValue, string result, char lastOp) {
        // end of DFS
        cout << result << endl;
        if (pos == num.size()) {
            if (lastOp == '*' && productValue == target || lastOp == '+' && target == 0)
                results.push_back(result);
            return;
        }
        
        for (size_t i = pos+1; i <= num.size(); i++) {
            string numStr = num.substr(pos, i-pos);
            int n = atoi(numStr.c_str());
            int t = 0;  // adjust target for - and +
            
            if (lastOp == '*')
                t = target - productValue;  // product is finished for + and -
            else
                t = target;

            if (pos == 0) {
                addOperators(num, i, target, n, numStr, '*');
            } else {
                addOperators(num, i, t-n, 0, result + "+" + numStr, '+');
                addOperators(num, i, t+n, 0, result + "-" + numStr, '-');
                addOperators(num, i, target, productValue*n, result + "*" + numStr, '*');
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        addOperators(num, 0, target, 0, "", '+');
        return results;
    }
};

class Solution {
public:
    vector<string> results;

    int calc(vector<string> eq, string &str) {
        stringstream ss;
        int last = 0;
        int product = 0;
        int res = 0;
        char mode = '+';
        
        for (auto &c : eq) {
            switch (c[0]) {
            case '+':
            case '-':
                res += product + last;
                product = last = 0;
                mode = c[0];
                break;
            case '*':
                if (mode != c[0]) {
                    mode = c[0];
                    product = last;
                    last = 0;
                }
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
                }
            }
            ss << c;
        }
        res += product + last;
        str = ss.str();
        //cout << str << "=" << res << endl;

        return res;
    }

    void addOperators(string num, size_t pos, int target, vector<string> eq) {
        // end of DFS
        if (pos == num.size()) {
            string str;
            if (calc(eq, str) == target)
                results.push_back(str);
            return;
        }
        
        for (size_t i = pos+1; i <= num.size(); i++) {
            string numStr = num.substr(pos, i-pos);

            if (pos == 0) {
                addOperators(num, i, target, {numStr});
            } else {
                auto nextEq = eq;
                nextEq.push_back("+");
                auto &op = nextEq.back();
                nextEq.push_back(numStr);
                
                addOperators(num, i, target, nextEq);
                op = "-";
                addOperators(num, i, target, nextEq);
                op = "*";
                addOperators(num, i, target, nextEq);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        addOperators(num, 0, target, {});
        return results;
    }
};

// Final DFS solution

class Solution {
public:
    vector<string> results;

    void addOperators(string num, size_t pos, int target, string eq, int last, int product, int res, char mode) {
        // end of DFS
        if (pos == num.size()) {
            res += product+last;
            //cout << eq << "=" << res << endl;
            if (target == res)
                results.push_back(eq);
            return;
        }
        
        for (size_t i = pos+1; i <= num.size(); i++) {
            string numStr = num.substr(pos, i-pos);
            long curr = atol(numStr.c_str());
        
            if (curr > numeric_limits<int>::max())
                break;
            // no numbers with heading 0s
            if (numStr.size() > 1 && numStr[0] == '0')
                continue;
            if (pos == 0) {
                addOperators(num, i, target, numStr, curr, 0, 0, '+');
            } else {
                int currProduct;
        
                addOperators(num, i, target, eq + "+" + numStr, curr, 0, res+product+last, '+');
                addOperators(num, i, target, eq + "-" + numStr, -curr, 0, res+product+last, '-');
                if (mode == '*')
                    currProduct = product * curr;
                else
                    currProduct = last * curr;
                addOperators(num, i, target, eq + "*" + numStr, 0, currProduct, res, '*');
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        addOperators(num, 0, target, "", 0, 0, 0, '+');
        return results;
    }
};

