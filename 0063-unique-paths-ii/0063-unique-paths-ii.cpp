class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int m, int n,int moves){
        if(m>=grid.size() || n>=grid[0].size() || grid[m][n]==1){
            return 0;
        }
        if(m==grid.size()-1 && n== grid[0].size()-1){
            return 1;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int down=0,right=0;
        if(m+1<grid.size()){
            down=solve(grid,dp,m+1,n,moves+1);
        }
        if(n+1<grid[0].size()){
            right=solve(grid,dp,m,n+1,moves+1);
        }
        dp[m][n]= down + right;
        return dp[m][n];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(),vector<int> (obstacleGrid[0].size(),-1));
        int ans = solve(obstacleGrid,dp,0,0,0);
        
        return ans;
    }
};