// Last updated: 08/01/2026, 20:01:17
1class Solution {
2public:
3    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
4        int m = nums1.size(), n = nums2.size();
5
6        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MIN / 2));
7
8        for (int i = m - 1; i >= 0; --i) {
9            for (int j = n - 1; j >= 0; --j) {
10                int prod = nums1[i] * nums2[j];
11
12                int startHere = prod;                     
13                int extendDiag = prod + dp[i + 1][j + 1]; 
14                int skip1 = dp[i + 1][j];                
15                int skip2 = dp[i][j + 1];
16
17                dp[i][j] = max({startHere, extendDiag, skip1, skip2});
18            }
19        }
20
21        return dp[0][0];
22    }
23};
24