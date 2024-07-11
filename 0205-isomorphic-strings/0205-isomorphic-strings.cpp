class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,char> umap;
        for(int i=0;i<s.length();i++){
            if(umap.find(s[i])==umap.end()){
                umap[s[i]]=t[i];
            }else{
                if(umap[s[i]]!=t[i]){
                    return false;
                }
            }
        }
        umap.clear();
        for(int i=0;i<t.length();i++){
            if(umap.find(t[i])==umap.end()){
                umap[t[i]]=s[i];
            }else{
                if(umap[t[i]]!=s[i]){
                    return false;
                }
            }
        }
        return true;
    }
};