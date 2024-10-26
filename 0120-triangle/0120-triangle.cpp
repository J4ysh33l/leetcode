class Solution {
public:
    int solve(vector<vector<int>>& triangle,int n,int i,vector<vector<int>>& dp){
        if(n==0){
            return triangle[n][0];
        }
        if(dp[n][i]!=INT_MAX){
            return dp[n][i];
        }
        int minSum=INT_MAX;
        if (i < triangle[n - 1].size()) {
            minSum =solve(triangle,n-1,i,dp);
        }
        if (i > 0) {
            minSum = min(minSum,solve(triangle,n-1,i-1,dp));
        }
        dp[n][i]=minSum + triangle[n][i];
        return dp[n][i];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans=INT_MAX;
        int n=triangle.size()-1;
        vector<vector<int>> dp(n+1,vector<int>(triangle[n].size(),INT_MAX));
        for(int i=0;i<triangle[n].size();i++){
            ans = min(ans,solve(triangle,n,i,dp));
        }
        return ans;
    }
};