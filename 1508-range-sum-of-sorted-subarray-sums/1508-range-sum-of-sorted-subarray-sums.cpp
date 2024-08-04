class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long> sumAr;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                sumAr.push_back(sum);
            }
        }
        sort(sumAr.begin(),sumAr.end());
        sum=0;
        int i=0;
        for(i=left-1;i<right;i++){
            sum+=sumAr[i];
        }
        return sum;
    }
};