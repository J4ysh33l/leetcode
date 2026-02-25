// Last updated: 26/02/2026, 00:01:31
1
2class Solution {
3public:
4    vector<int> sortByBits(vector<int>& arr) {
5        sort(arr.begin(), arr.end(), 
6        [](unsigned x, unsigned y){
7            return popcount(x)==popcount(y)?x<y
8            : popcount(x)<popcount(y);
9        });
10        return arr;
11    }
12};