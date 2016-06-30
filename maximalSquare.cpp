// https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int isSquare(vector<vector<char>>& matrix, int startX, int startY) {
        //cout << "x=" << startX << " y=" << startY << endl;
        for (int size = 1; ; size++) {
            if (startX+size >= matrix.size() || startY+size >= matrix[startX].size())
                return size;
            for (int x = 0; x <= size; x++)
                if (matrix[startX+x][startY+size] != '1')
                    return size;
            for (int y = 0; y <= size; y++)
                if (matrix[startX+size][startY+y] != '1')
                    return size;
        }
        return 0;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int size = 0;
        if (matrix.empty())
            return 0;
        
        for (int x = 0; x < matrix.size(); x++)
            for (int y = 0; y < matrix[x].size(); y++) {
                //cout << "[" << x << "," << y << "]" << "=" <<  matrix[x][y] << endl;
                if (matrix[x][y] == '1')
                    size = max(size, isSquare(matrix, x, y));
            }
        return size * size;
    }
};
