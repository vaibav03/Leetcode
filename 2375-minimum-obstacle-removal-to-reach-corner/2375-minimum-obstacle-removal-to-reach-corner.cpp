class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        vector<int> row = {1, -1, 0, 0};
        vector<int> col = {0, 0, 1, -1};

        q.push({0,0, 0});
        vis[0][0] = 0;

        while (!q.empty()) {
            auto node = q.top();
            q.pop();

            int obs = node[0];
            int x = node[1], y = node[2];
            for (int i = 0; i < 4; i++) {
                int newX = x + row[i], newY = y + col[i];
                if (newX >= 0 && newY >= 0 && newX < n && newY < m) {
                    int newObs = obs + grid[newX][newY];
                    if (newObs < vis[newX][newY]) {
                        vis[newX][newY] = newObs;
                        q.push({newObs, newX, newY});
                    }
                }
            }
        }

        return vis[n-1][m-1];
    }
};
