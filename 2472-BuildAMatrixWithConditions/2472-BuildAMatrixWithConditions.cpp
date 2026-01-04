// Last updated: 05/01/2026, 00:04:56
class Solution {
public:
    vector<int> topologicalSort(int k, vector<vector<int>>& conditions) {
    vector<vector<int>> graph(k + 1);
    vector<int> in_degree(k + 1, 0);
    
    for (auto& cond : conditions) {
        graph[cond[0]].push_back(cond[1]);
        in_degree[cond[1]]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= k; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> top_order;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        top_order.push_back(node);
        
        for (int neighbor : graph[node]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    if (top_order.size() == k) {
        return top_order;
    } else {
        return {};
    }
}

vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    vector<int> row_order = topologicalSort(k, rowConditions);
    vector<int> col_order = topologicalSort(k, colConditions);
    
    if (row_order.empty() || col_order.empty()) {
        return {};
    }
    
    unordered_map<int, int> row_pos, col_pos;
    for (int i = 0; i < k; ++i) {
        row_pos[row_order[i]] = i;
        col_pos[col_order[i]] = i;
    }
    
    vector<vector<int>> matrix(k, vector<int>(k, 0));
    for (int num = 1; num <= k; ++num) {
        matrix[row_pos[num]][col_pos[num]] = num;
    }
    
    return matrix;
}
};