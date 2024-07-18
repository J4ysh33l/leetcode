class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // Ensure mid is even
            if (mid % 2 == 1) {
                mid--;
            }
            
            // If mid and mid+1 form a pair, search right
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            } else {
                // If not, search left
                high = mid;
            }
        }
        
        return nums[low];
    }
};
