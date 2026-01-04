// Last updated: 05/01/2026, 00:04:04
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(int i=0;i<details.size();i++){
            int age=stoi(details[i].substr(11,2));
            cout<<age<<endl;
            if(age>60){
                ans++;
            }
        }
        return ans;
    }
};