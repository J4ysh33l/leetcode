class Solution {
public:
    int balancedStringSplit(string s) {
        stack<char> st;
        int output=0;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(s[i]=='L'){
                if(st.top()=='R'){
                    st.pop();
                    if(st.empty()){
                        output++;
                    }
                }else{
                    st.push('L');
                }
            }
            if(s[i]=='R'){
                if(st.top()=='L'){
                    st.pop();
                    if(st.empty()){
                        output++;
                    }
                }else{
                    st.push('R');
                }
            }
        }
        return output;
    }
};