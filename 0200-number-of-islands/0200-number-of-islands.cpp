class Solution {
public:
void bfs(vector<vector<char>> &g, vector<vector<int>> &vis, int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = 1;

    
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        auto node = q.front();
        q.pop();

        for (auto &dir : directions) {
            int f = node.first + dir.first;
            int s = node.second + dir.second;

            
            if (f >= 0 && f < g.size() && s >= 0 && s < g[0].size() && g[f][s] == '1' && !vis[f][s]) {
                q.push({f, s});
                vis[f][s] = 1;
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;

    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> vis(rows, vector<int>(cols, 0));
    int ans = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!vis[i][j] && grid[i][j] == '1') {
                bfs(grid, vis, i, j);
                ans++;
            }
        }
    }
    return ans;
}

};