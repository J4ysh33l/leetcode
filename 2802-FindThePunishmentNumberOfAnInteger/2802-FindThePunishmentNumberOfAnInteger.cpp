// Last updated: 05/01/2026, 00:03:57
class Solution {
public:
    bool punish(int num, int n) { 
        int sum = 0;
        if (n < num) return false;
        if (n == num) return true;

        int power = 1; // Used to extract digits properly
        while (n > 0) {
            sum = (n % 10) * power + sum;
            n /= 10;
            power *= 10;

            if (sum <= num && punish(num - sum, n)) { // Ensure sum does not exceed num
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (punish(i, i * i)) {
                sum += (i * i);
            }
        }
        return sum;
    }
};
