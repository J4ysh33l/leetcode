// Last updated: 05/01/2026, 00:02:33
class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
            int winners = 0;

    // Initialize a vector of unordered_maps to track the ball counts for each player
    std::vector<std::unordered_map<int, int>> playerBallCount(n);

    // Count the number of balls of each color picked by each player
    for (const auto& p : pick) {
        int player = p[0];
        int color = p[1];
        playerBallCount[player][color]++;
    }

    // Check if each player wins
    for (int i = 0; i < n; ++i) {
        for (const auto& entry : playerBallCount[i]) {
            if (entry.second >= i + 1) {
                winners++;
                break; // No need to check further, the player already wins
            }
        }
    }

    return winners;
}
};