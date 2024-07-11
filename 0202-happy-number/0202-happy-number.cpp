class Solution {
    bool happyCount(int n, unordered_map<int,int> umap){
        int product=0;
        while(n){
            product += (n%10)*(n%10);
            n/=10;
        }
        if(product==1){
            return true;
        }
        if(umap.find(product)==umap.end()){
            umap[product]++;
        }else{
            return false;
        }
        return happyCount(product,umap);
    }
public:
    bool isHappy(int n) {
        unordered_map<int,int> umap;
        int product=0;
        while(n){
            product += (n%10)*(n%10);
            n/=10;
        }
        if(product==1){
            return true;
        }
        if(umap.find(product)==umap.end()){
            umap[product]++;
        }else{
            return false;
        }
        return happyCount(product,umap);
    }
};