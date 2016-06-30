class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(s.size()+1);
        int maxSubStr = 0;
        
        m[0] = 0;
        for (int i = 1; i <= s.size(); i++) {
            char curr = s[i-1];
            bool dup = false;
            
            for (int j = i - 1 - m[i-1]; j < i - 1; j++)
                if (s[j] == curr) {
                    dup = true;
                    break;
                }
            m[i] = dup ? 1 : (m[i-1] + 1);
            maxSubStr = max(m[i], maxSubStr);
        }
        return maxSubStr;
    }
};

class Solution {
public:
    typedef unordered_map<char, int> MapType;

    int lengthOfLongestSubstring(string s) {
        MapType charPos;
        size_t res = 0;
        
        for (int i = 0; i < s.size(); i++) {
            char curr = s[i];
            MapType::iterator currIter;
            
            currIter = charPos.find(curr);
            if (currIter == charPos.end())
                charPos.insert(make_pair(curr, i));
            else {
                int pos = currIter->second;
                currIter->second = i;
                for (MapType::iterator i = charPos.begin(); i != charPos.end();) {
                    if (i->second <= pos)
                        i = charPos.erase(i);
                    else
                        ++i;
                }
            }
            res = max(res, charPos.size());
        }
        return res;
    }
};
