class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];

        // Iterate through the array starting from the second element
        for (size_t i = 1; i < nums.size(); ++i) {
            // Update the current sum
            currentSum = max(nums[i], currentSum + nums[i]);
            // Update the maximum sum if the current sum is greater
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};