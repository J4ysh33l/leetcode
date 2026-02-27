// Last updated: 27/02/2026, 20:10:14
1#include <iostream>
2#include <string>
3#include <vector>
4#include <queue>
5#include <set>
6#include <algorithm>
7
8using namespace std;
9
10class Solution {
11public:
12    int minOperations(string s, int k) {
13        int n = s.length();
14        int initial_zeros = count(s.begin(), s.end(), '0');
15        
16        // Two sets to keep track of UNVISITED zero-counts by parity (index 0 for even, 1 for odd)
17        set<int> unvisited[2];
18        for (int i = 0; i <= n; i++) {
19            unvisited[i % 2].insert(i);
20        }
21        
22        // Remove our starting point from the unvisited sets
23        unvisited[initial_zeros % 2].erase(initial_zeros);
24        
25        queue<int> q;
26        q.push(initial_zeros);
27        
28        // This acts as your iteration counter / level tracker
29        int operations = 0; 
30        
31        while (!q.empty()) {
32            int size = q.size();
33            
34            // Process everything at the current operation level
35            for (int i = 0; i < size; i++) {
36                int curr_zeros = q.front();
37                q.pop();
38                
39                // Target reached! Because it's BFS, this is guaranteed to be the minimum.
40                if (curr_zeros == 0) {
41                    return operations;
42                }
43                
44                // The exact math bounds you derived
45                int x_max = min(curr_zeros, k);
46                int x_min = max(0, k - (n - curr_zeros));
47                
48                int min_next_zeros = curr_zeros + k - 2 * x_max;
49                int max_next_zeros = curr_zeros + k - 2 * x_min;
50                
51                // Since the formula jumps by 2, all valid next states share this parity
52                int parity = min_next_zeros % 2;
53                
54                // O(log N) lookup to find the first unvisited state in our range
55                auto it = unvisited[parity].lower_bound(min_next_zeros);
56                
57                // Iterate only through valid, unvisited states up to our max bound
58                while (it != unvisited[parity].end() && *it <= max_next_zeros) {
59                    q.push(*it);
60                    // Erase it from the set so we NEVER loop over it again
61                    it = unvisited[parity].erase(it); 
62                }
63            }
64            operations++; // Increment level after exhausting the queue at this depth
65        }
66        
67        // The queue emptied out (all possible combinations visited) and we never hit 0
68        return -1;
69    }
70};