// Last updated: 05/01/2026, 00:04:59
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);

        // Mark shifts in the difference array
        for (auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            int delta = (direction == 1) ? 1 : -1;
            diff[start] += delta;
            if (end + 1 < n) {
                diff[end + 1] -= delta;
            }
        }

        // Calculate cumulative shifts
        int cumulativeShift = 0;
        for (int i = 0; i < n; ++i) {
            cumulativeShift += diff[i];
            // Normalize the shift to stay within the range of 26
            int shift = (cumulativeShift % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }

        return s;
    }
};
