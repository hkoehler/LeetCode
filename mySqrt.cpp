#include <iostream>
#include <limits>

using namespace std;

// binary search for upper-bound
class Solution {
public:
    int mySqrt(int x) {
        long start = 0;
        long end = x;
        
        cout << "x=" << x << endl;
        if (x < 0)
            return -1;
        if (x == 0)
            return 0;
        while (start < end) {
            long m = start + (end - start) / 2 + 1;
            if (m*m > x)
                end = m - 1;    // exclude m
            else if (m*m <= x)
                start = m;      // include m
            else {
                end = m;
                break;
            }
            //cout << m << " " << start << " " << end << endl;
        }
        cout << "end=" << end << endl;
        return start;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    
    sol.mySqrt(1);
    sol.mySqrt(2);
    sol.mySqrt(4);
    sol.mySqrt(9);
    sol.mySqrt(16);
    sol.mySqrt(17);
    sol.mySqrt(12345678);
    sol.mySqrt(numeric_limits<int>::max());
    return 0;
}
