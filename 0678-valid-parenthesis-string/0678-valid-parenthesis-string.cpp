class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st; // Stack to track indices of unmatched '('
        int star = 0; // Count of '*' characters
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i); // Push the index of '(' onto the stack
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop(); // Match '(' with ')'
                } else if (star > 0) {
                    star--; // Use a '*' as '(' to balance ')'
                } else {
                    return false; // Unmatched ')' without a '(' or '*'
                }
            } else if (s[i] == '*') {
                star++; // Count '*' characters
            }
        }
        
        // After processing all characters, check remaining unmatched '('
        while (!st.empty() && star > 0) {
            st.pop(); // Try to match remaining '(' with '*'
            star--; // Use '*' as ')'
        }
        
        return st.empty(); // If stack is empty, all '(' are matched
    }
};
