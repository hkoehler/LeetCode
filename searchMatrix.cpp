class Solution {
public:
    int searchRows(vector<vector<int>>& matrix, int target, int i, int j) {
        assert(i <= j);
        size_t cols = matrix[i].size();
        if (cols == 0)
            return -1;
        if (matrix[i][0] <= target && matrix[j][cols-1] >= target) {
            if (i == j)
                return i;
            int m = i + (j - i) / 2;
            int res1 = searchRows(matrix, target, i, m);
            if (res1 != -1)
                return res1;
            int res2 = searchRows(matrix, target, m+1, j);
            if (res2 != -1)
                return res2;
        }
        return -1;
    }
    
    bool searchRow(vector<int> &row, int target, int i, int j) {
        assert(i <= j);
        if (row.empty())
            return false;
        if (row[i] <= target && row[j] >= target) {
            if (i == j)
                return true;
            int m = i + (j - i) / 2;
            return searchRow(row, target, i, m) || searchRow(row, target, m+1, j);
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        int row = searchRows(matrix, target, 0, matrix.size() - 1);
        if (row == -1)
            return false;
        return searchRow(matrix[row], target, 0, matrix[row].size() - 1);
    }
};
