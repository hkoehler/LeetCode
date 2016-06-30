// https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int last = INT_MAX;
        int n = 0;
        
        for (auto c : s) {
            auto tmp = m[c];
            if (tmp > last) {
                n -= last;  // undo last
                n += tmp - last;
            } else
                n += tmp;
            last = tmp;
        }
        return n;
    }
};
