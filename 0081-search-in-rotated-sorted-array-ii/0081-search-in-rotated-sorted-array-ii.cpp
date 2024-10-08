class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int high = nums.size()-1;
        while(low<=high){
            int mid= low + (high-low)/2;
            if(nums[mid]==target){
                return true;
            }else if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }else if(target< nums[low]){
                if(nums[mid]< target){
                    low= mid;
                }else{
                    high= mid+1;
                }
            }else{
                if(nums[mid]<target){
                    low= mid+1;
                }else{
                    high=mid;
                }
            }
        }
        return false;
    }
};