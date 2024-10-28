class Solution {
public:
    // Helper function to expand around the center and find the palindrome length
    string expandFromCenter(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1); // Return the palindromic substring
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";

        string longest = s.substr(0, 1); // At least one character is a palindrome
        for (int i = 0; i < s.length(); i++) {
            // Expand around center once with i, i and once with i, i+1
            string pal = expandFromCenter(s, i, i);   // Odd-length center
            string palEven = expandFromCenter(s, i, i + 1); // Even-length center

            // Update longest palindrome if a longer one is found
            if (pal.length() > longest.length()) {
                longest = pal;
            }
            if (palEven.length() > longest.length()) {
                longest = palEven;
            }
        }
        return longest;
    }
};
