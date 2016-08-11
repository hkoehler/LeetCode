//! https://leetcode.com/problems/compare-version-numbers/

class Solution {
public:

    int parseVersion(const string &s, string::size_type &pos) {
        int c = 0;

        if (pos != string::npos) {
            auto nextPos = s.find('.', pos);
            auto n = (nextPos == string::npos) ? string::npos : (nextPos - pos);
            auto comp = s.substr(pos, n);
            
            if (!comp.empty())
                c = stoi(comp);
            pos = (nextPos != string::npos) ? nextPos+1 : string::npos;
        }
        return c;
    }

    int compareVersion(string version1, string version2) {
        string::size_type pos1 = 0, pos2 = 0;
        
        while (pos1 != string::npos || pos2 != string::npos) {
            int c1 = 0, c2 = 0;

            c1 = parseVersion(version1, pos1);
            c2 = parseVersion(version2, pos2);
            if (c1 > c2)
                return 1;
            if (c1 < c2)
                return -1;
        }
        return 0;
    }
};
