// Last updated: 08/02/2026, 00:31:53
1class Solution {
2public:
3    int minimumDeletions(string s) {
4        int n = s.size();
5        int f[n + 1];
6        memset(f, 0, sizeof(f));
7        int b = 0;
8        for (int i = 1; i <= n; ++i) {
9            if (s[i - 1] == 'b') {
10                f[i] = f[i - 1];
11                ++b;
12            } else {
13                f[i] = min(f[i - 1] + 1, b);
14            }
15        }
16        return f[n];
17    }
18};