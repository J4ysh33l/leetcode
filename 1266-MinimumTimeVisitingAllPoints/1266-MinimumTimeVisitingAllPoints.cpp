// Last updated: 13/01/2026, 00:16:44
1class Solution {
2public:
3    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
4        int travel=0;
5        for(int i=1;i<points.size();i++){
6            int x =abs(points[i-1][0]-points[i][0]);
7            int y =abs(points[i-1][1]-points[i][1]);
8            pair<int,int> diff = make_pair(x,y);
9            int diag = min(diff.first,diff.second);
10            int diffPoint=abs(diff.first-diff.second);
11
12            travel+=diag+diffPoint;
13
14        }
15        return travel;
16    }
17};