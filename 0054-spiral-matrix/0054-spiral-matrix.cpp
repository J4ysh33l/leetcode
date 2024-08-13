class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans; // Early return if the matrix is empty
        
        int rowStart = 0, rowEnd = matrix.size() - 1;
        int colStart = 0, colEnd = matrix[0].size() - 1;

        while (rowStart <= rowEnd && colStart <= colEnd) {
            // Traverse from left to right across the top row
            for (int col = colStart; col <= colEnd; ++col) {
                ans.push_back(matrix[rowStart][col]);
            }
            rowStart++; // Move down to the next row

            // Traverse down the right column
            for (int row = rowStart; row <= rowEnd; ++row) {
                ans.push_back(matrix[row][colEnd]);
            }
            colEnd--; // Move left to the next column

            // Traverse from right to left across the bottom row (if applicable)
            if (rowStart <= rowEnd) {
                for (int col = colEnd; col >= colStart; --col) {
                    ans.push_back(matrix[rowEnd][col]);
                }
            }
            rowEnd--; // Move up to the next row

            // Traverse up the left column (if applicable)
            if (colStart <= colEnd) {
                for (int row = rowEnd; row >= rowStart; --row) {
                    ans.push_back(matrix[row][colStart]);
                }
            }
            colStart++; // Move right to the next column
        }

        return ans;
    }
};
