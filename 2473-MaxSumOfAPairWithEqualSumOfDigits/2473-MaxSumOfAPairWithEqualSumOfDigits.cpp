// Last updated: 05/01/2026, 00:04:55
class Solution {
public:

    int dSum(int num){
        int n=0;
        while(num>0){
            n+=num%10;
            num/=10;
        }
        return n;
    }
    int maximumSum(vector<int>& nums) {
        int sum=-1;
        int maxSum=-1;
        unordered_map<int,int> umap;

        for(auto num: nums){
            int digiSum = dSum(num);
            cout<<digiSum<<endl;
            if(umap.find(digiSum)!= umap.end()){
                sum = num+umap[digiSum];
                maxSum=max(sum,maxSum);
                if(umap[digiSum]<num){
                    umap[digiSum]=num;
                }
            }else{
                umap[digiSum]=num;
            }
        }
        return maxSum;
    }
};