class Solution {
public:
    bool fill(vector<vector<char>>& board, int x, int y) {
        if (board[x][y] == 'X')
            return true;
        if (x == 0 || y == 0 || x == board.size() - 1 || y == board[x].size() - 1)
            return false;
        board[x][y] = 'X';
        return fill(board, x-1, y) && fill(board, x+1, y) && fill(board, x, y-1) && fill(board, x, y+1);
    }

    void solve(vector<vector<char>>& board) {
        if (board.size() < 2)
            return;
        for (int x = 1; x < board.size() - 1; x++)
            for (int y = 1; y < board[x].size() - 1; y++)
                if (board[x][y] == 'O') {
                    vector<vector<char>> b = board;
                    if (fill(b, x, y))
                        board = b;
                        return;
                }
    }
};

class Solution {
public:
    bool fill(vector<vector<char>> &board, int x, int y) {
        if (board[x][y] == 'X')
            return true;
        if (board[x][y] == 'H')
            return true;
        if (x == 0)
            return false;
        if (y == 0)
            return false;
        if (x == board.size() - 1)
            return false;
        if (y == board[x].size() -1)
            return false;
        board[x][y] = 'H';
        return true;
    }
    
    bool fillAll(vector<vector<char>> &board, int startx, int starty) {
        board[startx][starty] = 'H';
        for (int i = 0; i < board.size(); i++)
            for (int x = 0; x < board.size(); x++)
                for (int y = 0; y < board[x].size(); y++)
                    if (board[x][y] == 'H')
                        if (!fill(board, x-1, y) || !fill(board, x+1, y) || !fill(board, x, y-1) || !fill(board, x, y+1))
                            return false;
        return true;
    }
    
    vector<vector<char>> fillX(vector<vector<char>> &board) {
        for (int x = 0; x < board.size(); x++)
            for (int y = 0; y < board[x].size(); y++)
                if (board[x][y] == 'H')
                    board[x][y] == 'X';
        return board;
    }

    void solve(vector<vector<char>>& board) {
        if (board.size() < 2)
            return;
        for (int x = 1; x < board.size() - 1; x++)
            for (int y = 1; y < board[x].size() - 1; y++)
                if (board[x][y] == 'O') {
                    vector<vector<char>> b = board;
                    if (fillAll(b, x, y))
                        board = fillX(b);
                }
    }
};
