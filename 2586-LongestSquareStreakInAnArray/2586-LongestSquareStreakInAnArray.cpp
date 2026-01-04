// Last updated: 05/01/2026, 00:04:29
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<long long,int> umap;
        for(auto x:nums){
            umap[x]=1;
        }
        int ans=-1;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            long long number=nums[i];
            long long square= number*number;
            if(umap.find(square)!=umap.end()){
                umap[square]=umap[number]+1;
                ans= max(ans,umap[square]);
            }
        }
        return ans;
    }
};