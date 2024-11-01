class Solution {
public:
    string makeFancyString(string s) {
        stack<char> st;
        st.push(s[0]);
        char prev=st.top();
        if(s.length()<2){
            return s;
        }
        st.push(s[1]);
        char third=prev;
        prev= st.top(); 
        int i=2;
        while(i<s.length()){
            st.push(s[i]);
            char head= st.top();
            if(head==prev && head==third){
                st.pop();
            }else{
                third=prev;
                prev=head;
            }
            i++;
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};