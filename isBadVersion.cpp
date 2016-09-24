// https://leetcode.com/problems/first-bad-version/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1;
        int hi = n;
        
        while (lo < hi) {
            int m = lo + (hi - lo) / 2;
            
            if (isBadVersion(m)) {
                hi = m;
            } else {
                lo = m + 1;
            }
        }
        return hi;
    }
};
