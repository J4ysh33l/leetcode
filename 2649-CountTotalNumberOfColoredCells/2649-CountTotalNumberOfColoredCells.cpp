// Last updated: 05/01/2026, 00:04:19
class Solution {
public:
    long long coloredCells(int n) {
        return 1 + 4LL * n * (n - 1) / 2; 
    }
};