// Last updated: 04/03/2026, 03:06:49
1class Solution {
2public:
3    // Helper function to find the kth bit in the binary string S_n
4    char findKthBit(int n, int k) {
5        // Base case: if n = 1, S1 is "0"
6        if (n == 1) return '0';
7
8        // Length of Sn is 2^n - 1
9        int length = (1 << n) - 1;
10        int mid = (length / 2) + 1;
11
12        // If k is the middle bit, return '1'
13        if (k == mid) return '1';
14
15        // If k is in the left half
16        if (k < mid) {
17            return findKthBit(n - 1, k);  // Recur for the left half
18        } else {
19            // If k is in the right half, find its mirrored position in the left half
20            int mirroredK = length - k + 1;
21            // Invert the result for the mirrored position
22            return findKthBit(n - 1, mirroredK) == '0' ? '1' : '0';
23        }
24    }
25};