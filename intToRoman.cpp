// https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int num) {
        string str;
        vector<vector<string>> m;
        size_t pos = 0;
       
        m.emplace_back(vector<string>{"", "I","II","III","IV","V","VI","VII","VIII","IX"});
        m.emplace_back(vector<string>{"", "X","XX","XXX","XL","L","LX","LXX","LXXX","XC"});
        m.emplace_back(vector<string>{"", "C","CC","CCC","CD","D","DC","DCC","DCCC","CM"});
        m.emplace_back(vector<string>{"", "M","MM","MMM"});
        while (num) {
            int d = num % 10;
            str = m[pos][d] + str;
            num /= 10;
            pos++;
        }
        return str;
    }
};

