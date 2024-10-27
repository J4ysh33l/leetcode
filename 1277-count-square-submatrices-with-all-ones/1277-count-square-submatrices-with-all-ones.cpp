class Solution {
public:
    int solve(vector<vector<int>>& matrix,vector<vector<int>>& dp,int m, int n,int square){
        if(m>=dp.size() || n>=dp[0].size()){
            return 0;
        }
        if(dp[m][n]!=INT_MAX){
            return dp[m][n];
        }

        int minsq=INT_MAX;
        if(matrix[m][n]==0){
            dp[m][n]=0;
            return 0;
        }else{
            minsq=min(solve(matrix,dp,m+1,n,square),min(solve(matrix,dp,m+1,n+1,square),solve(matrix,dp,m,n+1,square)));
            dp[m][n]=min(dp[m][n],minsq+1);
        }
        return dp[m][n];
    }

    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),INT_MAX));
        int sum=0;
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                sum+=solve(matrix,dp,i,j,0);
            }
        }

        return sum;
    }
};