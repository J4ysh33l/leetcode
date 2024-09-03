#include <string>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        string numStr = "";
        
        // Step 1: Convert each character to its position in the alphabet
        for(char c : s) {
            int val = c - 'a' + 1;
            numStr += to_string(val);
        }
        
        // Step 2: Sum the digits `k` times
        int sum = 0;
        while(k > 0) {
            sum = 0;
            for(char c : numStr) {
                sum += c - '0';
            }
            numStr = to_string(sum);
            k--;
        }
        
        return sum;
    }
};
