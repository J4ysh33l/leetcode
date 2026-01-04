// Last updated: 05/01/2026, 00:04:24
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // Use a max heap to always pick the largest element
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        
        long long score = 0;

        // Perform k operations
        while (k--) {
            // Get the largest element from the heap
            int maxElement = maxHeap.top();
            maxHeap.pop();

            // Add the largest element to the score
            score += maxElement;

            // Replace the element with ceil(maxElement / 3)
            int newElement = (maxElement + 2) / 3;
            maxHeap.push(newElement);
        }

        return score;
    }
};
