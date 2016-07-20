// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        
        for (int i = 0; i < height.size(); i++)
            for (int k = i+1; k < height.size(); k++)
                res = max(res, min(height[i], height[k]) * abs(i - k));
        return res;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0;
        int j = height.size() - 1;
        
        while (i < j) {
            int h = min(height[i], height[j]);
            //cout << i << " " << j << " " << h << endl;
            res = max(res, h * (j - i));
            // find bigger area w/ bigger height
            while (height[i] <= h && i < j)
                i++;
            // find bigger area w/ bigger height
            while (height[j] <= h && i < j)
                j--;
        }
        return res;
    }
};
