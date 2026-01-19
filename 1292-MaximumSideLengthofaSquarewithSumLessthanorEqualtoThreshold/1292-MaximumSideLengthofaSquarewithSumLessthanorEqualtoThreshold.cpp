// Last updated: 19/01/2026, 23:57:58
1class Solution {
2public:
3    int maxSideLength(vector<vector<int>>& mat, int threshold) {
4        int m = mat.size(), n = mat[0].size();
5
6        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));
7
8        for (int i = 1; i <= m; i++) {
9            for (int j = 1; j <= n; j++) {
10                pref[i][j] =
11                    mat[i-1][j-1]
12                  + pref[i-1][j]
13                  + pref[i][j-1]
14                  - pref[i-1][j-1];
15            }
16        }
17
18        int maxSide = min(m, n);
19
20        while (maxSide > 0) {
21            for (int i = 0; i + maxSide <= m; i++) {
22                for (int j = 0; j + maxSide <= n; j++) {
23                    int sum =
24                        pref[i+maxSide][j+maxSide]
25                      - pref[i][j+maxSide]
26                      - pref[i+maxSide][j]
27                      + pref[i][j];
28                    if (sum <= threshold) return maxSide;
29                }
30            }
31            maxSide--;
32        }
33        return 0;
34    }
35};