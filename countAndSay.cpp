// https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 2; i <= n; i++) {
            stringstream ss;
            char curr = 'z';
            size_t count = 0;
            
            for (char c : s) {
                if (curr != 'z') {
                    if (c == curr) {
                        count++;
                        continue;
                    } else {
                        ss << count << curr;
                    }
                }
                curr = c;
                count = 1;
            }
            if (count) {
                ss << count << curr;
            }
            s = ss.str();
        }
        return s;
    }
};
