class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1){
            return 1;
        }
        int output=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[0][i]==grid[j][0]){
                    int k=0;
                    while(k<n){
                        if(grid[k][i]!=grid[j][k]){
                            break;
                        }
                        if(k==n-1){
                            output++;
                        }
                        k++;
                    }
                }
            }
        }
        return output;
    }
};