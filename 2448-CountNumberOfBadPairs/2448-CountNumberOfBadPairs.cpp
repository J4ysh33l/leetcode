// Last updated: 05/01/2026, 00:05:02
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        long long goodPairs = 0, n = nums.size(); 
        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;
            goodPairs += freq[key];
            freq[key]++;
        }
        return (n * (n - 1)) / 2 - goodPairs;
    }
};