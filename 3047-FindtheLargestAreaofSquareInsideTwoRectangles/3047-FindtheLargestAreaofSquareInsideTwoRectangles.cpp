// Last updated: 17/01/2026, 15:52:53
1class Solution {
2public:
3    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
4        long long maxSide=0;
5        for(int i=0;i<bottomLeft.size();i++){
6            for(int j=i+1;j<bottomLeft.size();j++){
7                long long side =0;
8                int xstart = max(bottomLeft[j][0],bottomLeft[i][0]);
9                int xend = min(topRight[j][0],topRight[i][0]);
10                int ystart = max(bottomLeft[j][1],bottomLeft[i][1]);
11                int yend = min(topRight[j][1],topRight[i][1]);
12                if(topRight[i][0]>bottomLeft[j][0] && topRight[i][1]>bottomLeft[j][1]){
13                    side = min(xend-xstart,yend-ystart);
14                    maxSide=max(side,maxSide);
15                }
16            }
17        } 
18        return maxSide*maxSide;
19    }
20};