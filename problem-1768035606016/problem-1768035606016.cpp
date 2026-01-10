// Last updated: 10/01/2026, 14:30:06
1class Solution {
2public:
3    int minimumDeleteSum(string s1, string s2) {
4        int m = s1.size();
5        int n = s2.size();
6
7        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
8        for(int i =0;i<=m;i++){
9            dp[i][0]=0;
10        }
11        for(int i =0;i<=n;i++){
12            dp[0][i]=0;
13        }
14
15        for(int i=1;i<=m;i++){
16            for(int j=1;j<=n;j++){
17                if(s1[i-1]==s2[j-1]){
18                    dp[i][j]=dp[i-1][j-1]+(s1[i-1]+0);
19                }else{
20                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
21                }
22            }
23        }
24
25        int keptSm= dp[m][n];
26        int sum1=0,sum2=0;
27        for(int i=0;i<m;i++){
28            sum1+= s1[i]+0;
29        }
30
31        for(int i=0;i<n;i++){
32            sum2+= s2[i]+0;
33        }
34
35        return sum1+sum2-2*keptSm;
36    }
37};