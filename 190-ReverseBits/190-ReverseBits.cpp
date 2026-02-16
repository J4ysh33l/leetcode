// Last updated: 17/02/2026, 01:15:20
1class Solution {
2public:
3    uint32_t reverseBits(uint32_t n) {
4        uint32_t ans=0;
5        // while(n){
6        //     ans <<= 1;          // Shift ans left to make space for the next bit
7        //     ans |= (n & 1);
8        //     n>>=1;
9        // }
10         for (int i = 0; i < 32; ++i) {
11            ans <<= 1;          // Shift ans left to make space for the next bit
12            ans |= (n & 1);     // Append the least significant bit of n to ans
13            n >>= 1;            // Shift n right to process the next bit
14        }
15        return ans;
16    }
17};