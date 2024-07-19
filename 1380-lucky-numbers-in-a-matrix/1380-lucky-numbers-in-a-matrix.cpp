class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> minRow;
        int minR=INT_MAX, maxC=INT_MIN;
        vector<int> maxCol;
        vector<int> ans;
        for(int i=0;i<matrix.size();i++){
            minR=INT_MAX;
            for(int j=0;j<matrix[0].size();j++){
                minR= min(minR,matrix[i][j]);
            }
            minRow.push_back(minR);
        }
        for(int i=0;i<matrix[0].size();i++){
            maxC=INT_MIN;
            for(int j=0;j<matrix.size();j++){
                maxC= max(maxC,matrix[j][i]);
                
            }
            maxCol.push_back(maxC);
            // if(maxCol[i]==minRow[i]){
            //     ans.push_back(maxCol[i]);
            // }
        }
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j]) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};