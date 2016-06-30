// https://leetcode.com/problems/multiply-strings/

class Solution {
public:
    vector<int>
    multiplyByDigit(vector<int> num, int d, int shift) {
        int carryOver = 0;
        vector<int> res(shift);
        
        assert(d >= 0 && d < 10);
        for (int &n : num) {
            auto tmp = n * d + carryOver;
            carryOver = tmp / 10;
            n = tmp % 10;
        }
        if (carryOver)
            num.push_back(carryOver);
        res.insert(res.end(), num.begin(), num.end());
        return res;
    }
    
    vector<int>
    add(vector<int> num1, vector<int> &num2) {
        bool carryBit = false;
        int pos1 = 0, pos2 = 0;
        vector<int> res;

        while (pos1 < num1.size() || pos2 < num2.size() || carryBit) {
            int n1 = 0, n2 = 0;
            
            if (pos1 < num1.size()) {
                n1 = num1[pos1];
                pos1++;
            }
            if (pos2 < num2.size()) {
                n2 = num2[pos2];
                pos2++;
            }
            auto tmp = n1 + n2 + (carryBit ? 1 : 0);
            carryBit = (tmp >= 10);
            res.push_back(tmp % 10);
        }
        return res;
    }
    
    vector<int> convertString(string s) {
        vector<int> num;
        
        for (int i = s.size() - 1; i >= 0; i--)
            num.push_back(s[i] - 0x30);
        return num;
    }

    string convertVec(vector<int> &num) {
        string str;
        
        while (!num.empty() && num.back() == 0)
            num.pop_back();
        if (num.empty())
            return "0";
        for (int i = num.size() - 1; i >= 0; i--)
            str.push_back(num[i] + 0x30);
        return str;
    }

    string multiply(string num1, string num2) {
        auto n1 = convertString(num1);
        auto n2 = convertString(num2);
        vector<int> res;
        size_t shift = 0;
        
        for (int d : n1) {
            auto tmp = multiplyByDigit(n2, d, shift++);
            res = add(res, tmp);
        }
        return convertVec(res);
    }
};
