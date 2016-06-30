// https://leetcode.com/problems/fraction-to-recurring-decimal/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        stringstream ss;
        unordered_map<int, int> rems;
        
        if (numerator == 0)
            return "0";
        if (numerator < 0 xor denominator < 0)
            ss << "-";
        long longNum = abs(long(numerator));
        long longDenom = abs(long(denominator));
        long rem = longNum;
        for (int i = 0;; i++) {
            long n = rem / longDenom;
            //cout << rem << " / " << longDenom << " = " << n << endl;
            //cout << "i=" << i << " n=" << n << " rem=" << rem << endl;
            ss << n;
            rem -= n * longDenom;
            rem *= 10;  // scale up remaining 
            if (rem == 0)
                break;
            else if (i == 0)
                ss << ".";
            if (rems.find(rem) != rems.end())
                break;
            else
                rems.insert(make_pair(rem, ss.str().size()));
        }
        
        auto s = ss.str();
        if (rem != 0) {
            auto pos = rems[rem];
            s.insert(pos, "(");
            s.append(")");
        }
        return s;
    }
};
