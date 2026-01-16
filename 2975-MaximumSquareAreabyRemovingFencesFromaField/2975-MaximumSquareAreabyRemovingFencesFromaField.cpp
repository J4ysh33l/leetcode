// Last updated: 16/01/2026, 23:48:25
1class Solution {
2public:
3    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
4        unordered_set<int> maxLen;
5        unordered_set<int> maxBre;
6        hFences.push_back(1);
7        hFences.push_back(m);
8        vFences.push_back(1);
9        vFences.push_back(n);
10        long long maxArea=-1;
11        for(int i=0;i<hFences.size();i++){
12            for(int j=i+1;j<hFences.size();j++){
13                maxLen.insert(abs(hFences[i]-hFences[j]));
14            }
15        }
16        for(int i=0;i<vFences.size();i++){
17            for(int j=i+1;j<vFences.size();j++){
18                maxBre.insert(abs(vFences[i]-vFences[j]));
19            }
20        }
21        long long MOD = 1e9 + 7;
22        
23        for(auto x:maxLen){
24            if(maxBre.count(x)){
25                maxArea=max(maxArea,(long long)x);
26            }
27        }
28
29        if(maxArea==-1){
30            return -1;
31        }
32        return (maxArea*maxArea)%MOD;
33    }
34};