// Last updated: 05/01/2026, 00:03:59
class Solution {
public:
    int backTrack(vector<vector<int>>& grid,vector<vector<int>>& dp, int m, int n){
        if(m>=grid.size() || n>=grid[0].size()){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int diagdown=0;
        int diagup=0;
        int right=0;
        int maxMove=0;
        if((m>0 && n+1<grid[0].size()) && grid[m-1][n+1]>grid[m][n]){
            diagup=1+backTrack(grid,dp,m-1,n+1);
        }
        if((n+1<grid[0].size()) && grid[m][n+1]>grid[m][n]){
            right=1+backTrack(grid,dp,m,n+1);
        }
        if((m+1<grid.size() && n+1<grid[0].size()) && grid[m+1][n+1]>grid[m][n]){
            diagdown=1+backTrack(grid,dp,m+1,n+1);
        }
        maxMove=max(diagup,max(diagdown,right));
        dp[m][n]=max(maxMove,dp[m][n]);
        return dp[m][n];
    }

    int maxMoves(vector<vector<int>>& grid) {
        int ans=0;
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++){
            ans= max(ans,backTrack(grid,dp,i,0));
        }
        return ans;
    }
};