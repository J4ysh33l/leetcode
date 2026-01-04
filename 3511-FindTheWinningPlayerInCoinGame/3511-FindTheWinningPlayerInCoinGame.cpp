// Last updated: 05/01/2026, 00:02:36
class Solution {
public:
    string losingPlayer(int x, int y) {
       while (true) {
        // Try to pick coins for Alice
        bool moveMade = false;
        for (int i = 0; i <= x; ++i) {
            if (i * 75 <= 115 && (115 - i * 75) % 10 == 0) {
                int j = (115 - i * 75) / 10;
                if (j <= y) {
                    x -= i;
                    y -= j;
                    moveMade = true;
                    break;
                }
            }
        }
        if (!moveMade) return "Bob"; // Alice cannot make a move, Bob wins

        // Try to pick coins for Bob
        moveMade = false;
        for (int i = 0; i <= x; ++i) {
            if (i * 75 <= 115 && (115 - i * 75) % 10 == 0) {
                int j = (115 - i * 75) / 10;
                if (j <= y) {
                    x -= i;
                    y -= j;
                    moveMade = true;
                    break;
                }
            }
        }
        if (!moveMade) return "Alice"; // Bob cannot make a move, Alice wins
    }
}
};