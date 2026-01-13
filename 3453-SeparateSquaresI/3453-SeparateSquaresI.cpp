// Last updated: 13/01/2026, 23:47:34
1class Solution {
2public:
3    double separateSquares(vector<vector<int>>& squares) {
4        double totalArea = 0;
5        double low = 2e9, high = 0; // Use safer initial bounds
6        
7        // 1. Calculate Total Area and Bounds carefully
8        for(auto& sq : squares) {
9            double y = sq[1];
10            double l = sq[2];
11            
12            // Cast to double to avoid Integer Overflow!
13            totalArea += l * l; 
14            
15            low = min(low, y);
16            high = max(high, y + l);
17        }
18
19        double halfArea = totalArea / 2.0;
20        
21        // 2. Binary Search with fixed iterations
22        // running 100 times guarantees precision without infinite loops
23        for(int i = 0; i < 100; i++) {
24            double mid = low + (high - low) / 2.0;
25            
26            if(calculateArea(squares, mid) >= halfArea) {
27                high = mid; // Too high, go down
28            } else {
29                low = mid;  // Too low, go up
30            }
31        }
32        
33        // 3. Return the calculated bound, NOT 0
34        return high; 
35    }
36
37    double calculateArea(vector<vector<int>>& squares, double currentY) {
38        double area = 0;
39        for(auto& sq : squares) {
40            double y = sq[1];
41            double l = sq[2];
42            double top = y + l; // Use double to avoid overflow
43            
44            if(y >= currentY) {
45                continue; // Square is fully above
46            } 
47            else if(top <= currentY) {
48                area += l * l; // Square is fully below
49            } 
50            else {
51                // Square is cut by the line
52                area += l * (currentY - y);
53            }
54        }
55        return area;
56    }
57};