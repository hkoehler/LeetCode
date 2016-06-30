// https://leetcode.com/problems/simplify-path/

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        string res;
        vector<string> p;
        
        // parse path
        while (getline(ss, token, '/')) {
            if (token.empty())
                continue;
            if (token == ".")
                continue;
            if (token == "..") {
                if (!p.empty())
                    p.pop_back();
                continue;
            }
            p.push_back(token);
        }
        for (auto comp : p) {
            res.append("/");
            res.append(comp);
        }
        return res.empty() ? "/" : res;
    }
};
