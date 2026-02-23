// Last updated: 23/02/2026, 23:13:43
1class Solution {
2public:
3    bool hasAllCodes(string s, int k) {
4        int req = 1 << k;
5        bitset<1048576> seen;
6        int mask = req - 1;
7        int hash = 0;
8
9        for (int i = 0; i < s.length(); ++i) {
10            hash = ((hash << 1) & mask) | (s[i] & 1);
11
12            if (i >= k - 1 && !seen[hash]) {
13                seen[hash] = 1;
14                req--;
15                if (req == 0) return true;
16            }
17        }
18
19        return false;
20    }
21};