class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<int>> vis(grid2.size(), vector<int>(grid2[0].size(), 0));
        queue<pair<int, int>> q;
        int ans = 0;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // 4 possible directions: up, down, left, right

        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[0].size(); j++) {
                if (!vis[i][j] && grid2[i][j] && grid1[i][j]) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    bool isSubIsland = true;

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        for (auto& dir : dirs) {
                            int nx = x + dir[0];
                            int ny = y + dir[1];

                            if (nx >= 0 && ny >= 0 && nx < grid2.size() && ny < grid2[0].size() && !vis[nx][ny] && grid2[nx][ny]) {
                                vis[nx][ny] = 1;
                                q.push({nx, ny});

                                if (!grid1[nx][ny]) {
                                    isSubIsland = false;  // This island in grid2 isn't fully within an island in grid1
                                }
                            }
                        }
                    }

                    if (isSubIsland) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
