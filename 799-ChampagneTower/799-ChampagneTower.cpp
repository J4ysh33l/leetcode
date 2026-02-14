// Last updated: 14/02/2026, 15:02:57
1class Solution {
2public:
3    double solve(int poured, int query_row, int query_glass, vector<double> &dp, int row, int glass){
4
5        // First row is called if poured is >1 then it will overflow hence output 1
6        if(query_row==0){
7            return (poured<=1.00)?poured:1;
8        }
9
10        // correct dp output
11        if(poured==0 || query_row==row ){
12            return min(1.0, dp[query_glass]);
13        }
14
15        // adding values
16        for(int i=glass;i<=glass+row;i++){
17            // dp[row][i] -> this row with glass i
18            double left = dp[i]-1;
19            if(left>0){
20                dp[i+row+1]+=left/2;
21                dp[i+row+2]+=left/2;
22            }
23        }
24        return solve(poured,query_row,query_glass,dp,row+1,glass+row+1);
25    }
26
27    double champagneTower(int poured, int query_row, int query_glass) {
28        vector<double> dp(5050,0);
29        dp[0]=poured;
30        query_glass+= ((query_row+1)*(query_row)/2);
31        return solve(poured,query_row,query_glass,dp,0,0);
32    }
33};