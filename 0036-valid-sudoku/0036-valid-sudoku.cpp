#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Initialize 2D vectors for row, column, and sub-box validity checks
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));

        // Traverse the board
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue; // Skip empty cells
                }
                
                int num = board[i][j] - '1'; // Convert char to an index (0-8)
                int k = (i / 3) * 3 + (j / 3); // Calculate box index
                
                if (row[i][num] || col[j][num] || box[k][num]) {
                    return false; // Invalid board
                }
                
                row[i][num] = col[j][num] = box[k][num] = true;
            }
        }

        return true;
    }
};
