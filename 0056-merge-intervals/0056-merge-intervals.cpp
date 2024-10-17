class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int last=intervals[0][1];
        vector<vector<int>> ans(intervals.size());
        if(intervals.size()<1){
            return ans;
        }
        int j=0;
        ans[j].push_back(intervals[0][0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>last){
                ans[j].push_back(last);
                ans[++j].push_back(intervals[i][0]);
            }
            last=max(last,intervals[i][1]);
        }
        if(ans[j].size()<2){
            ans[j].push_back(last);
        }
        ans.erase(ans.begin()+j+1,ans.end());
        return ans;
    }
};