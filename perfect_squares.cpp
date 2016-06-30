#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

#if 0
class Solution {
public:
    std::map<int, int> solutions;
    std::map<int, bool> squares;

    bool issquare(int n) {
        bool ret = false;
        if (squares.find(n) != squares.end())
            return squares[n];
        for (int i = 1; ; i++) {
            if (i * i == n) {
                ret = true;
                break;
            }
            if ( i * i > n) {
                ret = false;
                break;
            }
        }
        squares.insert(make_pair(n, ret));
        return ret;
    }
    
    int numSquares(int n) {
        size_t m = -1;
        
        if (solutions.find(n) != solutions.end()) {
            return solutions[n];
        }
        for (int i = n; i >= 1; i--) {
            if (issquare(i)) {
                if (i == n) {
                    m = 1;
                    break;
                }
                else
                    m = min(size_t(numSquares(n - i)) + 1, m);
            }
        }
        solutions.insert(make_pair(n, m));

        return m;
    }
};
#endif

#if 0
class Solution {
public:
    int numSquares(int n, bool top) {
        std::vector<bool> isSquare(n+1);
        
        for (int i = 1; ; i++)
            if (i * i > n)
                break;
            else
                isSquare[i*i] = true;
        
        vector<size_t> s(n+1);
        vector<vector<size_t>> numbers(n+1);
        s[1] = 1;
        numbers[1] = {1};
        for (size_t i = 2; i <= (size_t)n; i++)
            s[i] = (size_t) -1;
        for (size_t i = 2; i <= (size_t)n; i++)
            if (isSquare[i]) {
                s[i] = 1;
                numbers[i] = {i};
            } else
                for (size_t j = 1; j < i; j++)
                    if (isSquare[j] && s[i] > s[i-j] + 1) {
                        numbers[i] = numbers[i-j];
                        numbers[i].push_back(j);
                        s[i] = s[i-j] + 1;
                    }
        if (top) {
            for (auto i : numbers[n])
                std::cout << i << "+";
            std::cout << endl;
        }
        return s[n]; 
    }
};
#endif

class Solution {
public:
    int numSquares(int n) {
        std::vector<size_t> s;

        s.push_back(0);
        for (size_t i = 1; i <= size_t(n); i++) {
            s.push_back((size_t) -1);
            for (size_t j = 1; j*j <= i; j++) {
                s[i] = min(s[i - j*j] + 1, s[i]);
            }
       }
       return s[n];
    }
};


int main(int argc, char *argv[])
{
    Solution sol;
    std::cout << sol.numSquares(atoi(argv[1])) << std::endl;
    return 0;
}

