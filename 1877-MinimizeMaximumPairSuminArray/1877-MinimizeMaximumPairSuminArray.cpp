// Last updated: 25/01/2026, 04:54:46
1class Solution {
2public:
3    int minPairSum(vector<int>& nums) {
4        int min = INT_MAX, max = INT_MIN;
5        int freq[100001] = {0};
6        for(int i = 0; i < nums.size(); i++) {
7            if(nums[i] < min) min = nums[i];
8            if(nums[i] > max) max = nums[i];
9            freq[nums[i]]++;
10        }
11        int max_sum = 0, l = min, r = max;
12        while(l <= r) {
13            if(freq[l] == 0) l++;
14            else if(freq[r] == 0) r--;
15            else {
16                max_sum = fmax(max_sum, l + r);
17                freq[l]--;
18                freq[r]--;
19            }
20        }
21        return max_sum;
22    }
23};