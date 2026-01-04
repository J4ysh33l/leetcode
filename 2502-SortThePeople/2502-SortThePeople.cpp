// Last updated: 05/01/2026, 00:04:46
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> sorted;
        vector<string> name;
        for(int i=0;i<names.size();i++){
            sorted.push_back({heights[i], names[i]});
        }
        sort(sorted.begin(),sorted.end());
        for(int i=0;i<names.size();i++){
            name.push_back(sorted[names.size()-(i+1)].second);
        }
        return name;
    }
};