// Last updated: 05/03/2026, 22:33:53
1class Solution {
2public:
3    int minOperations(string& s) {
4        //op[0] count op need for "0101.." 
5        //op[1] count op need for "1010.."
6        int n=s.size(), op[2]={0};
7        for(int i=0; i<n; i+=2)
8            op[s[i]=='0']++;
9            
10        for (int i=1; i<n; i+=2)
11            op[s[i]=='1']++;
12        return min(op[0], op[1]);
13    }
14};
15
16auto init = []()
17{ 
18    ios::sync_with_stdio(0);
19    cin.tie(0);
20    cout.tie(0);
21    return 'c';
22}();