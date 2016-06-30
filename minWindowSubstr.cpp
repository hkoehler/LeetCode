// https://leetcode.com/problems/minimum-window-substring/
 
class Solution {
public:

    string minWindow(string s, string t) {
        unordered_map<char, size_t> pos;
        size_t minWinSize = INT_MAX;
        string minWin;
        
        // insert all characters
        for (auto c : t)
            pos[c] = string::npos;
            
        for (size_t i = 0; i < s.size(); i++) {
            auto p = pos.find(s[i]);
            
            // found character
            if (p != pos.end()) {
                p->second = i;
                
                // calculate window size
                size_t first = string::npos;
                for (auto c : pos) {
                    if (c.second == string::npos) {
                        first = string::npos;
                        break;
                    }
                    first = min(first, c.second);
                }
                if (first != string::npos && minWinSize > i - first) {
                    minWinSize = i - first;
                    minWin = s.substr(first, i - first + 1);
                }
            }
        }
        return minWin;
    }
};

// handle duplicates

class Solution {
public:

    string minWindow(string s, string t) {
        unordered_map<char, size_t> counters;
        unordered_map<char, size_t> maxCounters;
        size_t minWinSize = INT_MAX;
        size_t beginWin = string::npos;
        string minWin;
        
        // count all characters
        for (auto c : t)
            maxCounters[c]++;
            
        for (size_t i = 0; i < s.size(); i++) {
            char c = s[i];
            auto p = maxCounters.find(c);
            
            // not interested in character
            if (p == maxCounters.end())
                continue;

            // found begining of window
            if (beginWin == string::npos)
                beginWin = i;
            char firstChar = s[beginWin];
            // count char
            counters[c]++;
            //cout << "count "  << c << " " << counters[c] << " firstChar " << firstChar << endl;
            
            // move window while first character in window is redundant
            while (counters[firstChar] > maxCounters[firstChar]) {
                counters[firstChar]--;
                for (beginWin++; beginWin <= i; beginWin++) {
                    char c2 = s[beginWin];
                    firstChar = c2;
                    if (maxCounters.find(c2) != maxCounters.end()) {
                        //cout << "shrink window " << beginWin << endl;
                        break;
                    }
                }
            }

            // is window complete?
            bool winComplete = (maxCounters.size() == counters.size());
            if (winComplete)
                for (auto counter : counters)
                    if (counter.second < maxCounters[counter.first]) {
                        winComplete = false;
                        break;
                    }
            //cout << "window complete " << winComplete << " window size " << i - beginWin << endl;
            
            // calculate window size
            if (winComplete && minWinSize > i - beginWin) {
                minWinSize = i - beginWin;
                minWin = s.substr(beginWin, i - beginWin + 1);
                //cout << "window " << minWin << " minWinSize=" << minWinSize << endl;
            }
        }
        return minWin;
    }
};
