class Solution {
public:

    bool solve(vector<int>&nums,vector<int>& dp,int index){
        if(index==nums.size()-1){
            return true;
        }

        if (dp[index] != -1) {
            return dp[index] == 1;
        }
        for (int j = 1; j <= nums[index]; j++) {
            if (index + j < nums.size() && solve(nums, dp, index + j)) {
                dp[index] = 1;
                return true;
            }
        }
        
        dp[index] = 0;  
        return false;
    }


    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        bool ans = solve(nums,dp,0);
        return ans;
    }
};