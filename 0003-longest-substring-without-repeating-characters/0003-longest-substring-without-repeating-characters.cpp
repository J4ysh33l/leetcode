class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0, right = 0;
        int maxLen = 0;
        unordered_set<char> charSet; // Use a set to track characters in the current window

        while (right < n) {
            if (charSet.find(s[right]) == charSet.end()) {
                // Character not in the set, add it and update maxLen
                charSet.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
                right++;
            } else {
                // Character in the set, remove the leftmost character and move left pointer
                charSet.erase(s[left]);
                left++;
            }
        }

        return maxLen;
    }
};
