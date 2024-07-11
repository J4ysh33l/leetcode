class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> umap;
        unordered_map<string,char> tmap;
        vector<string> strings;
        int j=0,k=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                strings.push_back(s.substr(k+1,j));
                k=i;
                j=0;
            }else if(i+1==s.length()){
                strings.push_back(s.substr(k+1,j+1));
            }else{
                j++;
            }
        }
        if(strings.size()!= pattern.length()){
            return false;
        }
        for(int i=0;i<strings.size();i++){
            cout<<strings[i]<<pattern[i]<<endl;
            if(umap.find(pattern[i])==umap.end()){
                umap[pattern[i]]=strings[i];
            }else{
                if(umap[pattern[i]]!=strings[i]){
                    return false;
                }
            }
        }
        for(int i=0;i<pattern.length();i++){
            if(tmap.find(strings[i])==tmap.end()){
                tmap[strings[i]]=pattern[i];
            }else{
                if(tmap[strings[i]]!=pattern[i]){
                    return false;
                }
            }
        }
        return true;
    }
};