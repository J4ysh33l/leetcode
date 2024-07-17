class Solution {
    void solve(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int> output,vector<bool> used){
        if(output.size()==nums.size()){
            ans.push_back(output);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(!used[j]){
                output.push_back(nums[j]);
                used[j]=true;
                solve(nums,i+1,ans,output,used);
                output.pop_back();
                used[j]=false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        vector<bool> used(nums.size(), false);
        solve(nums,0,ans,output,used);
        return ans;
    }
};