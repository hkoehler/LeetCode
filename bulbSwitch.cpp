// https://leetcode.com/problems/bulb-switcher/
class Solution {
public:
    int bulbSwitch(int n) {
        int ret = 0;
        char bm[n / 8 + 1];
        
        memset(bm, 0, sizeof(bm));
        for (int i = 0; i < n; i++) {
            for (int b = i; b < n; b += i+1) {
                //cout << "round=" << i << " toggle " << b << endl;
                if ((bm[b / 8] & (0x1 << (b % 8))) == 0) {
                    bm[b / 8] |= (char(0x1) << (b % 8));
                    //cout << "switch on " << b << " " << hex << (char)bm[b / 8] << endl;
                } else {
                    bm[b / 8] &= (~(char(0x1) << (b % 8)));
                    //cout << "switch off " << b << " " << hex << (char)bm[b / 8] << endl;
                }
            }
            //for (int b = 0; b < n; b++)
            //    cout << (bm[b / 8] & (char(0x1) << (b % 8)) != 0);
            //cout << endl;
        }
        for (int b = 0; b < n; b++)
            if ((bm[b / 8] & (0x1 << (b % 8))) != 0)
                ret++;
        return ret;
    }
};
