class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> ans;
        vector<string> ret;
        sort(folder.begin(),folder.end());
        for(auto x:folder){
            string str="";
            for(int i=0;i<x.length();i++){
                if(x[i]=='/' && str.length()!=0){
                    if(ans.find(str)!=ans.end()){
                        break;
                    }
                }
                str+=x[i];
            }
            ans.insert(str);
        }

        for(auto x:ans){
            ret.push_back(x);
        }
        return ret;
    }
};