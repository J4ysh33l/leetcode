// Last updated: 05/01/2026, 00:03:58
class Solution {
public:
    int minLength(string s) {
        stack<char> sc;
        for(int i = 0; i < s.length(); i++) {
            if(!sc.empty() && ((s[i] == 'B' && sc.top() == 'A') || (s[i] == 'D' && sc.top() == 'C'))) {
                sc.pop();
            } else {
                sc.push(s[i]);
            }
        }
        return sc.size();
    }
};
