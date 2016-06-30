#include <array>
#include <string>
#include <locale>
#include <iostream>

using namespace std;

class Solution {
        std::array<bool, 128> bm;
        std::array<int, 128> win;
        size_t num_chars;
        size_t min, max;
public:
    size_t winSize() {
        size_t count = 0;
	min = max = -1;
        
        for (int i = 0; i < win.size(); i++) {
            if (bm[i] && win[i] != -1) {
                count++;
                if (min == -1)
                    min = win[i];
                if (max == -1)
                    max = win[i];
                if (win[i] < min)
                    min = win[i];
                if (win[i] > max)
                    max = win[i];
            }
        }
        if (count == num_chars)
            return max - min + 1;
        else
            return -1;
    }

    string minWindow(string s, string t) {
        size_t min_win = -1;
        size_t begin, end;
        
        num_chars = t.size();
        for (int i = 0; i < win.size(); i++)
            win[i] = -1;
        for (auto &c : t)
            bm[c] = 1;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (bm[c])
                win[c] = i;
            if (winSize() < min_win) {
                min_win = winSize();
                begin = min;
                end = max;
            }
        }
        if (min_win == -1)
            return "";
        return s.substr(begin, end - begin + 1);
    }
};

int main(int argc, char *argv[])
{
	Solution sol;
	std::cout << sol.minWindow(argv[1], argv[2]) << std::endl;
	return 0;
}
