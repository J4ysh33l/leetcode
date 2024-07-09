class Solution {
    void isPossible(int& ans,int sum, vector<int>& nums, int n,int i, int target){
        int arrSum=0,x=i;
        for(x;x<n;x++){
            arrSum+=nums[x];
        }
        cout<<arrSum;
        if(arrSum>target){
            isPossible(ans,sum,nums,n,i+1,target);
        }else if(arrSum<target){
            ans=n-i+1;
            return;
        }else if(arrSum<=target){
            ans=n-i;
        }
    }
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),sum=0,ans=n;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        cout<<sum;
        if(sum<target){
            return 0;
        }else{
            isPossible(ans,sum,nums,n,0,target);
        }
        return ans;
    }
};