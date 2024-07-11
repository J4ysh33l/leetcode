class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n=nums.size(),maxSeq=1,seq=1;
        if(n==0){
            return 0;
        }else if(n==1){
            return 1;
        }
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>0;i--){
            if(nums[i]==(nums[i-1]+1)){
                seq= seq+1;
                cout<<nums[i]<<seq<<endl;
                maxSeq=max(maxSeq,seq);
            }else{
                seq=1;
            }
        }
        return maxSeq;
    }
};