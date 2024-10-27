class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0, leftSum = 0;
        
        // Calculate total sum of the array
        for (int num : nums) {
            totalSum += num;
        }
        
        // Iterate through the array to find the pivot index
        for (int i = 0; i < nums.size(); i++) {
            // Check if the current index is a pivot
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;
            }
            // Update leftSum for the next iteration
            leftSum += nums[i];
        }
        
        // If no pivot index is found, return -1
        return -1;
    }
};
