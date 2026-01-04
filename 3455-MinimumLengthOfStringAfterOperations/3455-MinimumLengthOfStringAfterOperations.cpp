// Last updated: 05/01/2026, 00:02:54
class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> umap;
        int ans=0;
        for(auto c: s){
            umap[c]++;
        }
        for(auto x: umap){
            ans+=(x.second%2)? 1: 2;
        }
        return ans;
    }
};