class Solution {
public:
    int bfs(vector<vector<int>> grid, int i, int j) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({0, {i, j}});
        
        vector<vector<int>> vec = {{0, 0, 1, -1}, {1, -1, 0, 0}}; 
        vector<vector<int>> cost(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        int n = grid.size(), m = grid[0].size();
        
        while (!q.empty()) {
            auto curr = q.top();
            q.pop();
            int i = curr.second.first, j = curr.second.second, curr_cost = curr.first;
            
            if (curr_cost > cost[i][j]) continue;  
            cost[i][j] = curr_cost;
            
            if (i == n - 1 && j == m - 1) {
                return curr_cost;
            }
            
            for (int ind = 0; ind < 4; ind++) {
                int new_i = i + vec[0][ind];
                int new_j = j + vec[1][ind];
                
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m) {
                    int new_cost = (grid[i][j] == ind + 1) ? curr_cost : curr_cost + 1;
                    
                    if (new_cost < cost[new_i][new_j]) {
                        cost[new_i][new_j] = new_cost;
                        q.push({new_cost, {new_i, new_j}});
                    }
                }
            }
        }

        return -1;  
    }

    int minCost(vector<vector<int>>& grid) {
        return bfs(grid, 0, 0);
    }
};
