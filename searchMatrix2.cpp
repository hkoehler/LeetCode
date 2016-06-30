// https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchRow(vector<int> &row, int target, int i, int j) {
        if (row[i] > target || row[j] < target)
            return false;
        while (i <= j) {
            int m = i + (j - i) / 2;
            
            if (row[m] < target)
                i = m+1;
            else if (row[m] > target)
                j = m-1;
            else
                return true;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = -1, j = matrix.size() - 1;
        
        for (int c = 0; c < matrix.size(); c++) {
            if (matrix[c].front() <= target && matrix[c].back() >= target)
                if (i == -1)
                    i = c;
                else
                    j = c;
        }
        
        cout << "i=" << i << " j=" << j << endl;
        for (auto row : matrix)
            if (searchRow(row, target, i, j))
                return true;
        return false;
    }
};

class Solution {
public:
    bool binarySearch(vector<int> arr, int target, int &lowerBound, int &upperBound) {
        if (arr[lowerBound] > target) {
            upperBound = lowerBound;
            return false;
        }
        if (arr[upperBound] < target) {
            lowerBound = upperBound;
            return false;
        }

        while (upperBound >= lowerBound) {
            int middle = lowerBound + (upperBound - lowerBound) / 2;
            if (arr[middle] < target)
                lowerBound = middle + 1;
            else if(arr[middle] > target)
                upperBound = middle - 1;
            else {
                upperBound = lowerBound = middle;
                return true;
            }
        }
        return false;
    }
    
    void searchCol(vector<vector<int>>& matrix, int target, int &i, int &j) {
        int lowerBound, upperBound;
        
        lowerBound = 0;
        upperBound = matrix.front().size() - 1;
        binarySearch(matrix.front(), target, lowerBound, upperBound);
        j = lowerBound;
        i = upperBound;
        if (matrix.size() > 1) {
            lowerBound = 0;
            upperBound = matrix.back().size() - 1;
            binarySearch(matrix.back(), target, lowerBound, upperBound);
            i = upperBound;
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i, j;
        
        searchCol(matrix, target, i, j);
        //cout << "i=" << i << " j=" << j << endl;
        for (auto row : matrix) {
            int lowerBound = i;
            int upperBound = j;
            if (binarySearch(row, target, lowerBound, upperBound))
                return true;
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix.front().size() - 1;
        
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] < target)
                i++;
            else
                j--;
        }
        return false;
    }
};

