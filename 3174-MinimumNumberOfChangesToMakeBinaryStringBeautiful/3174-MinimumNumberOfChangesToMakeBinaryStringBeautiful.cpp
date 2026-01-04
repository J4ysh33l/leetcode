// Last updated: 05/01/2026, 00:03:37
class Solution {
public:
    int minChanges(string s) {
       int c=0;
        for(int i=0;i<s.size()-1;i=i+2){
            if(s[i]!=s[i+1])c++;
        }
        return c;
    }
};