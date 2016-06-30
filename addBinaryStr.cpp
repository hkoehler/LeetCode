class Solution {
public:
    string addBinary(string a, string b) {
        int carryOver = 0;
        string res;
        
        while (!a.empty() || !b.empty() || carryOver) {
            int tmp = carryOver;
            
            if (!a.empty()) {
                tmp += a.back() - '0';
                a.pop_back();
            }
            if (!b.empty()) {
                tmp += b.back() - '0';
                b.pop_back();
            }
            res = (tmp % 2 ? "1" : "0") + res;
            carryOver = tmp / 2;
        }
        return res;
    }
};
