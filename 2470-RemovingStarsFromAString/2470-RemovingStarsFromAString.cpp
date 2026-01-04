// Last updated: 05/01/2026, 00:04:58
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        stack<char> sc;
        for(int i=0;i<s.length();i++){
            if(!sc.empty() && s[i]=='*'){
                sc.pop();
            }else{
                sc.push(s[i]);
            }
        }
        string str="";
        while(!sc.empty()){
            st.push(sc.top());
            sc.pop();
        }
        while(!st.empty()){
            str+= st.top();
            st.pop();
        }
        return str;
    }
};