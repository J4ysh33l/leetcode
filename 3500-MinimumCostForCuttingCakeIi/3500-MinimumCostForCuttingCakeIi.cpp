// Last updated: 05/01/2026, 00:02:40
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
     sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());
        
        int h = 0, v = 0;
        int horizontalPieces = 1, verticalPieces = 1;
        long long totalCost = 0;
        
        // Use a greedy approach to pick the largest cut available
        while (h < horizontalCut.size() && v < verticalCut.size()) {
            if (horizontalCut[h] >= verticalCut[v]) {
                totalCost += horizontalCut[h] * verticalPieces;
                horizontalPieces++;
                h++;
            } else {
                totalCost += verticalCut[v] * horizontalPieces;
                verticalPieces++;
                v++;
            }
        }
        
        // Add the remaining cuts if there are any left
        while (h < horizontalCut.size()) {
            totalCost += horizontalCut[h] * verticalPieces;
            h++;
        }
        
        while (v < verticalCut.size()) {
            totalCost += verticalCut[v] * horizontalPieces;
            v++;
        }
        
        return totalCost;
    }
};