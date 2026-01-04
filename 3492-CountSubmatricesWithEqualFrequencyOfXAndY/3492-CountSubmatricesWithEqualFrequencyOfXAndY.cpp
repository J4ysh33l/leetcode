// Last updated: 05/01/2026, 00:02:42
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> pX(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> pY(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pX[i + 1][j + 1] = pX[i][j + 1] + pX[i + 1][j] - pX[i][j] + (grid[i][j] == 'X' ? 1 : 0);
                pY[i + 1][j + 1] = pY[i][j + 1] + pY[i + 1][j] - pY[i][j] + (grid[i][j] == 'Y' ? 1 : 0);
            }
        }
        int c = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    for (int k = i; k < m; ++k) {
                        for (int l = j; l < n; ++l) {
                            int cX = pX[k + 1][l + 1] - pX[i][l + 1] - pX[k + 1][j] + pX[i][j];
                            int cY = pY[k + 1][l + 1] - pY[i][l + 1] - pY[k + 1][j] + pY[i][j];
                            if (cX == cY && cX > 0) {
                                c += 1;
                            }
                        }
                    }
                }
            }
        }
        return c;
    }
};