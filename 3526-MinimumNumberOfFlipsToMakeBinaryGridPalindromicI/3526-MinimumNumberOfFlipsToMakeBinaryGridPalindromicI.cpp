// Last updated: 05/01/2026, 00:02:31
#include <vector>
#include <algorithm>

class Solution {
public:
    int minFlips(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int output = 0;

        auto countRowFlips = [&](int row) {
            int flips = 0;
            for (int i = 0; i < n / 2; ++i) {
                if (grid[row][i] != grid[row][n - i - 1]) {
                    flips++;
                }
            }
            return flips;
        };

        auto countColFlips = [&](int col) {
            int flips = 0;
            for (int i = 0; i < m / 2; ++i) {
                if (grid[i][col] != grid[m - i - 1][col]) {
                    flips++;
                }
            }
            return flips;
        };

        int rowFlips = 0;
        int colFlips = 0;

        for (int i = 0; i < m; ++i) {
            rowFlips += countRowFlips(i);
        }
        for (int j = 0; j < n; ++j) {
            colFlips += countColFlips(j);
        }
        output = std::min(rowFlips, colFlips);
        return output;
    }
};
