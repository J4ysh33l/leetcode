// Last updated: 05/01/2026, 00:03:12
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int x) {
        int ans = numBottles;
        while (numBottles >= x) {
            numBottles -= x - 1, x++, ans++;
        }
        return ans;
    }
};