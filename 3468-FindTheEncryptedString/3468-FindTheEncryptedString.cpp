// Last updated: 05/01/2026, 00:02:49
class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ch;
        for(int i=0;i<s.length();i++){
            ch.push_back(s[(i+k)%s.length()]);
        }
        return ch;
    }
};