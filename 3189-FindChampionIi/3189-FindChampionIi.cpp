// Last updated: 05/01/2026, 00:03:36
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& v) {
        int m=v.size();
        vector<int>in(n,0);
        for(int i=0;i<m;i++)
        {
            in[v[i][1]]++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
                ans.push_back(i);
        }
        if(ans.size()>1)
            return -1;
        return ans[0];
    }
};