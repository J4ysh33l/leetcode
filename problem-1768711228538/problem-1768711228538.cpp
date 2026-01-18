// Last updated: 18/01/2026, 10:10:28
1class Solution {
2public:
3    bool isMagicSquare(vector<vector<int>>& grid, int r, int c, int k) {
4    // 1. Initialize sums
5    vector<int> rowSum(k, 0);
6    vector<int> colSum(k, 0);
7    int diagSum = 0;
8    int antiDiagSum = 0;
9
10    // 2. Loop through relative coordinates (0 to k-1)
11    for (int i = 0; i < k; i++) {
12        for (int j = 0; j < k; j++) {
13            int val = grid[r + i][c + j]; // ADD OFFSETS HERE
14
15            rowSum[i] += val;
16            colSum[j] += val;
17
18            // Relative diagonals are easy now
19            if (i == j) diagSum += val;
20            if (i + j == k - 1) antiDiagSum += val;
21        }
22    }
23
24    // 3. Validation
25    // First, check if the two diagonals match
26    if (diagSum != antiDiagSum) return false;
27
28    // Then check all rows and columns against the diagonal
29    for (int i = 0; i < k; i++) {
30        if (rowSum[i] != diagSum || colSum[i] != diagSum) {
31            return false;
32        }
33    }
34
35    return true;
36}
37
38    int largestMagicSquare(vector<vector<int>>& grid) {
39        int m = grid.size();
40        int n = grid[0].size();
41        int maxPossible = min(m, n);
42
43        for (int k = maxPossible; k >= 2; k--) {
44            for (int i = 0; i <= m - k; i++) {
45                for (int j = 0; j <= n - k; j++) {
46                    if (isMagicSquare(grid, i, j, k)) {
47                        return k;
48                    }
49                }
50            }
51        }
52        
53        return 1; 
54    }
55};