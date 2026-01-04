// Last updated: 05/01/2026, 00:05:01
class Solution {
public:
    string smallestNumber(string pattern) {
        int index=1;
        stack<string>st;
        st.push(to_string(index));
        stack<string> drop;
        string ans="";
        for(int i=0;i<pattern.length();i++){
            if(pattern[i]=='D'){
                string rm = st.top();
                st.pop();
                drop.push(rm);
            }else{
                while(drop.size()>0){
                    string rm = drop.top();
                    drop.pop();
                    st.push(rm);
                }
            }
            ++index;
            st.push(to_string(index));
            cout<<st.top()<<endl;
        }
        while(drop.size()>0){
                    string rm = drop.top();
                    drop.pop();
                    st.push(rm);
                }
        while(st.size()>0){
            string rm = st.top();
            st.pop();
            ans+=rm;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};