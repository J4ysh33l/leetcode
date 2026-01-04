// Last updated: 05/01/2026, 00:02:46
class Solution {
public:
    string getSmallestString(string s) {
        for(int i=1;i<s.length();i++){
            if(s[i]%2==s[i-1]%2 && s[i]<s[i-1]){
                swap(s[i],s[i-1]);
                break;
            }
        }
        return s;
    }
};