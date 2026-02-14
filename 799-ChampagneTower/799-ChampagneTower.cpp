// Last updated: 14/02/2026, 14:38:47
1class Solution {
2public:
3    double solve(int poured, int query_row, int query_glass, vector<vector<double>> &dp, int row, int glass){
4        // if glasses are not present at that row
5        if(query_glass > query_row){
6            return 0;
7        }
8
9        // First row is called if poured is >1 then it will overflow hence output 1
10        if(query_row==0){
11            return (poured<=1.00)?poured:1;
12        }
13
14        // correct dp output
15        if(poured==0 || query_row==row ){
16            return min(1.0, dp[query_row][query_glass]);
17        }
18
19        // adding values
20        for(int i=0;i<=row;i++){
21            // dp[row][i] -> this row with glass i
22            double left = dp[row][i]-1;
23            if(left>0){
24                dp[row+1][i]+=left/2;
25                dp[row+1][i+1]+=left/2;
26            }
27        }
28        return solve(poured,query_row,query_glass,dp,row+1,0);
29    }
30
31    double champagneTower(int poured, int query_row, int query_glass) {
32        vector<vector<double>> dp(query_row + 2, vector<double>(query_row + 2, 0));
33        dp[0][0]=poured;
34        return solve(poured,query_row,query_glass,dp,0,0);
35    }
36};