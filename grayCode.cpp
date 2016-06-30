// https://leetcode.com/problems/gray-code/

class Solution {
    vector<int> codes;
public:
    
    vector<int> grayCode(int n) {
        if (n == 0)
            return {0};
        vector<int> codes;
        vector<int> subCodes = grayCode(n-1);
        for (int i = 0; i < subCodes.size(); i++)
            codes.push_back(subCodes[i]);
        for (int i = subCodes.size() - 1; i >= 0; i--)
            codes.push_back((1 << (n - 1)) | subCodes[i]);
        return codes;
    }
};
