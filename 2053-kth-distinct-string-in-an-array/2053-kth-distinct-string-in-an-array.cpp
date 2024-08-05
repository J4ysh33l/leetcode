class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int index=1;
        unordered_map<string,int>umap;
        for(auto x:arr){
            umap[x]++;
        } 
        for(auto x:arr){
            if(umap[x]==1){
                if(index==k){
                    return x;
                }
                index++;
            }
        }
        return "";
    }
};