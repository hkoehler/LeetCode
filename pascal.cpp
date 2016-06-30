class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1}, prevRow;
        
        if (rowIndex == 0)
            return row;
        prevRow = row;
        for (int i = 1; i <= rowIndex; i++) {
            row = {1};
            for (int j = 0; j < prevRow.size()-1; j++)
                row.push_back(prevRow[j] + prevRow[j+1]);
            row.push_back(1);
            prevRow = row;
        }
        return row;
    }
};
