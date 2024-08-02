class Solution {
public:
    int maximum69Number (int num) {
        int x=num,count=0;
        vector<int> ans;
        while(x>0){
            ans.push_back(x%10);
            x/=10;
        }
        x=0;
        int i=0;
        for(i=ans.size()-1;i>=0;i--){
            if(ans[i]==6){
                ans[i]=9;
                break;
            }
            x=x*10+ans[i];
        }
        for(i;i>=0;i--){
            x=x*10+ans[i];
        }
        return x;
    }
};