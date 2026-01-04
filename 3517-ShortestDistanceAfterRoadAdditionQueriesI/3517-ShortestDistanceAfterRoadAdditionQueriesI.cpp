// Last updated: 05/01/2026, 00:02:34
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> adj(n);
        const int INF = numeric_limits<int>::max();
    vector<int> answer;

    // Initialize the initial road connections
    for (int i = 0; i < n - 1; ++i) {
        adj[i].emplace_back(i + 1, 1);
    }

    // Function to compute shortest path from city 0 to city n-1
    auto dijkstra = [&]() {
        vector<int> dist(n, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1];
        };

    // Process each query
    for (const auto& query : queries) {
        int ui = query[0], vi = query[1];
        adj[ui].emplace_back(vi, 1);
        answer.push_back(dijkstra());
    }

    return answer;
    }
};