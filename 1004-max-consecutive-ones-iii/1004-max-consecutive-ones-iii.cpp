class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen=0,len=0,left=0,right=0,zeros=0;
        while(right<nums.size()){
            if(nums[right]==0){
                zeros++;
            }
            right++;
            while(zeros>k){
                if(nums[left]==0){
                    zeros--;
                }
                left++;
            }
        }
        return maxLen;
    }
};