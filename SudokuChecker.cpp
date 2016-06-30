class Solution {
public:
    bool check(set<char> &nums, char n) {
        if (n == '.')
            return true;
        if (nums.find(n) != nums.end())
            return false;
        nums.insert(n);
        return true;
    }

    bool validateBox(vector<vector<char>>& board, int row, int col) {
        set<char> nums;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (check(nums, board[row+i][col+j]) == false)
                    return false;
        return true;
    }
    
    bool validateColumn(vector<vector<char>>& board, int col) {
        set<char> nums;

        for (int i = 0; i < 9; i++)
            if (check(nums, board[i][col]) == false)
                return false;
        return true;
    }

    bool validateRow(vector<vector<char>>& board, int row) {
        set<char> nums;

        for (int i = 0; i < 9; i++)
            if (check(nums, board[row][i]) == false)
                return false;
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
            if (validateRow(board, i) == false)
                return false;
        for (int i = 0; i < 9; i++)
            if (validateColumn(board, i) == false)
                return false;
        for (int i = 0; i < 9; i += 3)
            for (int j = 0; j < 9; j += 3)
                if (validateBox(board, i, j) == false)
                    return false;
        return true;
    }
};
