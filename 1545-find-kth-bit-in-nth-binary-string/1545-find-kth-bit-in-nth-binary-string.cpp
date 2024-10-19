class Solution {
public:
    // Helper function to find the kth bit in the binary string S_n
    char findKthBit(int n, int k) {
        // Base case: if n = 1, S1 is "0"
        if (n == 1) return '0';

        // Length of Sn is 2^n - 1
        int length = (1 << n) - 1;
        int mid = (length / 2) + 1;

        // If k is the middle bit, return '1'
        if (k == mid) return '1';

        // If k is in the left half
        if (k < mid) {
            return findKthBit(n - 1, k);  // Recur for the left half
        } else {
            // If k is in the right half, find its mirrored position in the left half
            int mirroredK = length - k + 1;
            // Invert the result for the mirrored position
            return findKthBit(n - 1, mirroredK) == '0' ? '1' : '0';
        }
    }
};
