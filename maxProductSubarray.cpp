// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n1, n2, res;
        
        res = n1 = n2 = numeric_limits<int>::min();
        for (int i = 0; i < nums.size(); i++) {
            //cout << " n1=" << n1 << " n2=" << n2 << endl;
            if (nums[i] == 0) {
                n1 = n2 = numeric_limits<int>::min();
                res = max(res, 0);
                continue;
            }
            if (n1 == numeric_limits<int>::min())
                n1 = nums[i];
            else
                n1 *= nums[i];
            if (n2 == numeric_limits<int>::min()) {
                if (nums[i] * n1 < 0)
                    n2 = nums[i];
            } else
                n2 *= nums[i];
            res = max(res, max(n1, n2));
            //cout << " n1=" << n1 << " n2=" << n2 << endl;
            //cout << nums[i] << " " << res << endl;
        }

        return res;
    }
};
