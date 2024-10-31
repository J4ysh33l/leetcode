class Solution {
public:
    bool solve(string s1, string s2, string s3, int i, int j, int k , vector<vector<int>>&dp){
        
        if(i==s1.size() && j==s2.size() && k==s3.size()){
            dp[i][j]=1;
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool one=false,two=false;
        if(s1[i]==s3[k]){
            one= solve(s1,s2,s3,i+1,j,k+1,dp);
        }
        if(s2[j]==s3[k]){
            two= solve(s1,s2,s3,i,j+1,k+1,dp);
        }
        dp[i][j]=(one||two);
        return dp[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {
        int i=s1.size(),j=s2.size(),k=s3.size();
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> dp(i+1, vector<int> (k+1,-1));
        bool ans= solve(s1,s2,s3,0,0,0,dp);
        return ans;
    }
};