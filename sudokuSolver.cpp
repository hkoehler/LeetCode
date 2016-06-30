#include <set>
#include <vector>
#include <iostream>

#include <cstring>
#include <cassert>

using namespace std;

class Solution {
public:

    void print(vector<vector<char>> &board) {
        cout << "[";
        for (int x = 0; x < 9; x++) {
            cout << "\"";
            for (int y = 0; y < 9; y++)
                cout << board[x][y];
            cout << "\"";
            if (x == 8)
                cout << "]";
            else
                cout << ",";
        }
        cout << endl;
    }
    
    unsigned short invalidNums(char b[9][9], int x, int y) {
        unsigned short nums = 0;

        assert(b[x][y] == 0);
        for (int i = 0; i < 9; i++) {
            nums |= 0x1 << b[x][i];
            nums |= 0x1 << b[i][y];
        }
        auto boxX = x / 3;
        auto boxY = y / 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                nums |= 0x1 << b[i + 3 * boxX][j + 3 * boxY];
        return nums;
    }
    
    bool solve(char b[9][9], int x, int y) {
        char bb[9][9];
    
        memcpy(bb, b, sizeof(bb));
        do {
            if (b[x][y] == 0) {
                auto nums = invalidNums(b, x, y);
                for (int n = 1; n <= 9; n++) {
                    if ((nums & (0x1 << n)) == 0) {
                        bb[x][y] = n;
                        if (solve(bb, x, y)) {
                            memcpy(b, bb, sizeof(bb));
                            return true;
                        }
                    }
                }
                return false;
            }
            if (++x == 9) {
                x = 0;
                ++y;
            }
       } while (y < 9);
       memcpy(b, bb, sizeof(bb));
       return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        char b[9][9];
        for (int x = 0; x < 9; x++)
            for (int y = 0; y < 9; y++)
                if (board[x][y] == '.')
                    b[x][y] = 0;
                else
                    b[x][y] = board[x][y] - '0';
        solve(b, 0, 0);
        for (int x = 0; x < 9; x++)
            for (int y = 0; y < 9; y++)
                board[x][y] = '0' + b[x][y];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<char>> board;

    cin.ignore(1);  // [
    for (int x = 0; x < 9; x++) {
        cin.ignore(1);  // "
        board.push_back(vector<char>(9));
        for (int y = 0; y < 9; y++) {
            char c;
            
            cin >> c;
            board[x][y] = c;
        }
        cin.ignore(1);  // "
        cin.ignore(1);  // , or ]
    }

    s.solveSudoku(board);
    s.print(board);
    return 0;   
}


