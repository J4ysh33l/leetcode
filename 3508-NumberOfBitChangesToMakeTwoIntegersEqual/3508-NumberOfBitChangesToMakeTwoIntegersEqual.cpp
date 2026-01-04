// Last updated: 05/01/2026, 00:02:38
class Solution {
public:
    int minChanges(int n, int k) {
        int changes = 0;
        
        while (n > 0 || k > 0) {
            int n_bit = n & 1;
            int k_bit = k & 1;
            
            // If k has a 1-bit where n has a 0-bit, it's impossible
            if (k_bit == 1 && n_bit == 0) {
                return -1;
            }
            
            // Count changes needed to turn 1-bits in n to 0-bits
            if (n_bit == 1 && k_bit == 0) {
                changes++;
            }
            
            n >>= 1;
            k >>= 1;
        }
        
        return changes;
    }
};