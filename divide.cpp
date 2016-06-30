class Solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0;
        long rem = abs(long(dividend));
        int shift = sizeof(int) * 8 - 1;
        int msb = 0x1 << shift;
        
        if (divisor == 1)
            return dividend;
        if (divisor == 0)
            return numeric_limits<int>::max();
        if (abs(long(divisor)) > abs(long(dividend)))
            return 0;
        if (dividend == numeric_limits<int>::min() &&
            divisor == numeric_limits<int>::min())
            return 1;
        if (dividend == numeric_limits<int>::max() &&
            divisor == numeric_limits<int>::max())
            return 1;
        if (divisor == -1)
            if (dividend == numeric_limits<int>::min())
                return numeric_limits<int>::max();
            else
                return (dividend ^ -1) + 1;

        for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
            long sum = (long(abs(divisor)) << i);
            long subRes = 0x1 << i;
            
            if (sum <= rem) {
                res += subRes;
                rem -= sum;
            }
            cout << "rem=" << rem << " res=" << res << endl;
        }
        if ((dividend & msb) != 0 ^ (divisor & msb) != 0)
            res = (res ^ -1) + 1;
        return res;
    }
};
