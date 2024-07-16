class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m=nums2.size();
        vector<int> nums;
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }else{
                nums.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            nums.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            nums.push_back(nums2[j]);
            j++;
        }
        n= nums.size();
        if(n%2==0){
            double result=nums[n/2]+nums[(n/2)-1];
            // cout<<nums1[mid]<<nums1[mid-1]<<endl;
            return result/2.0;
        }
            return nums[n/2];
        
    }
};