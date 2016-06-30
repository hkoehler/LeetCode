// https://leetcode.com/problems/maximum-product-of-word-lengths/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<uint32_t> bitmaps;
        size_t res = 0;
        
        // calculate char bitmaps of each word
        for (auto word : words) {
            uint32_t bitmap = 0;
            
            for (auto c : word)
                bitmap |= 0x1 << (c - 'a');
            bitmaps.push_back(bitmap);
        }
        
        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < words.size(); j++)
                if (i != j && (bitmaps[i] & bitmaps[j]) == 0)
                    res = max(res, words[i].size() * words[j].size());
        return res;
    }
};
