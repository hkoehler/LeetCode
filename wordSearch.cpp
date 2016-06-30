// https://leetcode.com/problems/word-search/

class Solution {
public:
    bool search(vector<vector<char>>& board, string word, int pos, int x, int y) {
        // consumed the whole word
        if (pos == word.size())
            return true;
        // check boundaries
        if (x < 0 || x >= board.size())
            return false;
        if (y < 0 || y >= board[x].size())
            return false;
        char t = board[x][y];
        if (t == word[pos]) {
            // don't visit a cell more than once
            board[x][y] = '\0';
            bool ret = search(board, word, pos+1, x+1, y) ||
                       search(board, word, pos+1, x-1, y) ||
                       search(board, word, pos+1, x, y+1) ||
                       search(board, word, pos+1, x, y-1);
            board[x][y] = t;
            return ret;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int x = 0; x < board.size(); x++)
            for (int y = 0; y < board[x].size(); y++)
                if (search(board, word, 0, x, y))
                    return true;
        return false;
    }
};
