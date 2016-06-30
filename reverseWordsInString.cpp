// https://leetcode.com/problems/reverse-words-in-a-string/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        if (s.empty())
            return;
    
        // sanitize string
        bool ws = true;
        for (auto c = s.begin(); c != s.end();) {
            if (isspace(*c)) {
                if (ws) {
                    c = s.erase(c);
                    continue;
                } else
                    ws = true;
            } else
                ws = false;
            c++;
        }
        if (ws && !s.empty())
            s.erase(s.end()-1);

        // reverse string
        auto strBegin = s.begin();
        auto strEnd = s.end() - 1;
        while (strBegin < strEnd)
            swap(*strBegin++, *strEnd--);
        
        auto wordBegin = s.end();
        for (auto c = s.begin(); c != s.end(); c++) {
            // end of word
            if (isspace(*c)) {
                // reverse word
                if (wordBegin != s.end()) {
                    auto wordEnd = --c;
                    while (wordBegin < wordEnd)
                        swap(*wordBegin++, *wordEnd--);
                    wordBegin = s.end();
                }
            } else if (wordBegin == s.end()) {
                wordBegin = c;
            }
        }
        // reverse word
        if (wordBegin != s.end()) {
            auto wordEnd = s.end() - 1;
            while (wordBegin < wordEnd)
                swap(*wordBegin++, *wordEnd--);
        }
    }
};

/*class Solution {
public:
    void reverseWords(string &s) {
        string s2;
        vector<size_t> words;
        bool ws = true;
        
        // find words
        for (size_t i = 0; i < s.size(); i++)
            if (isspace(s[i])) {
                if (ws)
                    continue;
                ws = true;
            } else if (ws) {
                words.push_back(i);
                ws = false;
            }
        for (auto word = words.rbegin(); word != words.rend(); word++) {
            if (word != words.rbegin())
                s2.push_back(' ');
            size_t count = 0;
            for (size_t i = *word; !isspace(s[i]) && i < s.size(); i++)
                count++;
            s2.append(s, *word, count);
        }
        s = s2;
    }
};*/

int main(int argc, char *argv[]) {
    Solution sol;
    string s;

    getline(cin, s);    
    sol.reverseWords(s);
    cout << "\"" << s << "\"" << endl;
    return 0;
}
