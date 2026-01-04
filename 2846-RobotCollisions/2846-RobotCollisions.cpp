// Last updated: 05/01/2026, 00:03:53

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<tuple<int, int, char, int>> robots(n);
        
        // Create a vector of tuples with position, health, direction, and index
        for (int i = 0; i < n; ++i) {
            robots[i] = {positions[i], healths[i], directions[i], i};
        }

        // Sort robots by their positions
        sort(robots.begin(), robots.end());

        stack<tuple<int, int, char, int>> stk;
        vector<int> surviving_healths(n, -1);

        for (const auto& robot : robots) {
            int pos, health, idx;
            char dir;
            tie(pos, health, dir, idx) = robot;

            if (dir == 'R') {
                stk.push(robot);
            } else {
                while (!stk.empty() && get<2>(stk.top()) == 'R') {
                    auto r_robot = stk.top();
                    stk.pop();
                    int r_pos, r_health, r_idx;
                    char r_dir;
                    tie(r_pos, r_health, r_dir, r_idx) = r_robot;

                    if (r_health > health) {
                        if (r_health - 1 > 0) {
                            stk.push({r_pos, r_health - 1, r_dir, r_idx});
                        }
                        health = -1;
                        break;
                    } else if (r_health < health) {
                        health -= 1;
                    } else {
                        health = -1;
                        break;
                    }
                }
                if (health > 0) {
                    surviving_healths[idx] = health;
                }
            }
        }

        while (!stk.empty()) {
            auto r_robot = stk.top();
            stk.pop();
            int r_pos, r_health, r_idx;
            char r_dir;
            tie(r_pos, r_health, r_dir, r_idx) = r_robot;
            surviving_healths[r_idx] = r_health;
        }

        // Collect surviving healths in the order of the original indices
        vector<int> result;
        for (int health : surviving_healths) {
            if (health != -1) {
                result.push_back(health);
            }
        }

        return result;
    }
};