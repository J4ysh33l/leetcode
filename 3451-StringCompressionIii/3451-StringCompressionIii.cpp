// Last updated: 05/01/2026, 00:02:56
#include <string>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int n = word.size();
        
        int i = 0;
        while (i < n) {
            char current_char = word[i];
            int count = 0;
            
            // Count up to 9 occurrences of the current character
            while (i < n && word[i] == current_char && count < 9) {
                count++;
                i++;
            }
            
            comp += to_string(count);
            comp += current_char;
        }
        
        return comp;
    }
};
