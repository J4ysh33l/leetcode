class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return {-1, -1};
        }

        vector<int> ans(2, -1);
        
        // Find the leftmost (first) occurrence of the target
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        if (start < n && nums[start] == target) {
            ans[0] = start;
        } else {
            return {-1, -1};
        }

        // Find the rightmost (last) occurrence of the target
        start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] <= target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        if (end >= 0 && nums[end] == target) {
            ans[1] = end;
        } else {
            return {-1, -1};
        }

        return ans;
    }
};
