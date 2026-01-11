// Last updated: 11/01/2026, 14:30:42
1class Solution {
2public:
3    int maximalRectangle(vector<vector<char>>& matrix) {
4        if (matrix.empty()) return 0;
5
6        int m = matrix.size();
7        int n = matrix[0].size();
8        vector<int> heights(n, 0);
9        int maxArea = 0;
10
11        for (int i = 0; i < m; i++) {
12            for (int j = 0; j < n; j++) {
13                if (matrix[i][j] == '1')
14                    heights[j] += 1;
15                else
16                    heights[j] = 0;
17            }
18
19            stack<int> st;
20            for (int j = 0; j <= n; j++) {
21                int currHeight = (j == n) ? 0 : heights[j];
22
23                while (!st.empty() && currHeight < heights[st.top()]) {
24                    int h = heights[st.top()];
25                    st.pop();
26
27                    int left = st.empty() ? -1 : st.top();
28                    int width = j - left - 1;
29
30                    maxArea = max(maxArea, h * width);
31                }
32                st.push(j);
33            }
34        }
35        return maxArea;
36    }
37};
38