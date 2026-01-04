// Last updated: 05/01/2026, 00:02:55
class Solution {
    void solve(int n, vector<string>& ans, string output) {
        if (n == 0) {
            ans.push_back(output);
            return;
        }
        solve(n - 1, ans, output + '0');
        solve(n - 1, ans, output + '1');
    }
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string output = "";
        solve(n, ans, output);
        
        vector<string> valid_ans;
        for (const string& s : ans) {
            bool isValid = true;
            for (int i = 0; i < s.length() - 1; i++) {
                if (s[i] == '0' && s[i + 1] == '0') {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                valid_ans.push_back(s);
            }
        }
        
        return valid_ans;
    }
};
