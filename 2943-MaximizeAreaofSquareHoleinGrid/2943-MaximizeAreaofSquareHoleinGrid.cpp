// Last updated: 15/01/2026, 12:47:02
1class Solution {
2public:
3    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
4        sort(hBars.begin(),hBars.end());
5        sort(vBars.begin(),vBars.end());
6        int length=1;
7        int breadth=1;
8        int maxLen=1,maxBre=1;
9
10        for(int i=1;i<hBars.size();i++){
11            if(hBars[i]==hBars[i-1]+1){
12                length++;
13            }else{
14                length=1;
15            }
16            maxLen=max(length,maxLen);
17        }
18
19        for(int i=1;i<vBars.size();i++){
20            if(vBars[i]==vBars[i-1]+1){
21                breadth++;
22            }else{
23                breadth=1;
24            }
25            maxBre=max(breadth,maxBre);
26        }
27        return pow(min(maxBre+1,maxLen+1),2);
28    }
29};