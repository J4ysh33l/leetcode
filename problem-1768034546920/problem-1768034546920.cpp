// Last updated: 10/01/2026, 14:12:26
1class Solution {
2public:
3    int createDp(vector<vector<int>> &dp, string &s1, string &s2, int m, int n,int i,int j){
4        if(i>=m||j>=n){
5            return 0;
6        }
7        if(dp[i][j]!=-1){
8            return dp[i][j];
9        }
10        if(s1[i]==s2[j]){
11           dp[i][j]= createDp(dp,s1,s2,m,n,i+1,j+1)+(s1[i]+0);
12        }else{
13            dp[i][j]=max(createDp(dp,s1,s2,m,n,i+1,j),createDp(dp,s1,s2,m,n,i,j+1));
14        }
15        return dp[i][j];        
16    }
17
18    int minimumDeleteSum(string s1, string s2) {
19        int m = s1.size();
20        int n = s2.size();
21
22        vector<vector<int>> dp(m, vector<int>(n, -1));
23
24        int keptSm= createDp(dp,s1,s2,m,n,0,0);
25        int sum1=0,sum2=0;
26        for(int i=0;i<m;i++){
27            sum1+= s1[i]+0;
28        }
29
30        for(int i=0;i<n;i++){
31            sum2+= s2[i]+0;
32        }
33
34        return sum1+sum2-2*keptSm;
35    }
36};