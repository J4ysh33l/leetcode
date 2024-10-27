#include <queue>
#include <string>

class Solution {
public:
    string predictPartyVictory(string senate) {
        std::queue<int> radiant, dire;
        int n = senate.size();
        
        // Initialize queues with the positions of each party's senators
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }
        
        // Simulate the rounds
        while (!radiant.empty() && !dire.empty()) {
            int rIndex = radiant.front();
            int dIndex = dire.front();
            radiant.pop();
            dire.pop();
            
            // The senator with the smaller index bans the other and rejoins the queue
            if (rIndex < dIndex) {
                radiant.push(rIndex + n);  // Rejoin at the end of the next round
            } else {
                dire.push(dIndex + n);  // Rejoin at the end of the next round
            }
        }
        
        // Determine the winner
        return radiant.empty() ? "Dire" : "Radiant";
    }
};
