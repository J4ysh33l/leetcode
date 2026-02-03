// Last updated: 04/02/2026, 02:29:07
1class Solution {
2public:
3    bool isTrionic(vector<int>& nums) {
4        int n = nums.size(), peak = n - 1, valley = 0;
5
6        for (int i = 0; i < n - 1; i++) {
7            if (peak == n - 1 && nums[i] >= nums[i + 1])
8                peak = i;
9            if (valley == 0 && nums[n - 1 - i] <= nums[n - 2 - i])
10                valley = n - 1 - i;
11            if (peak < valley)
12                return isDecreasing(nums, peak, valley);
13        }
14
15        return false;
16    }
17
18    bool isDecreasing(vector<int>& A, int a, int b) {
19        if (a == 0 || b == A.size() - 1) return false;
20        for (int i = a; i < b; i++)
21            if (A[i] <= A[i + 1]) return false;
22        
23        return true;
24    }
25};
26