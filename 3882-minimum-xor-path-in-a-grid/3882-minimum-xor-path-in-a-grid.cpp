class Solution {
public:
    int ans = INT_MAX;
    vector<vector<vector<int>>> dp;

    void rec(vector<vector<int>>& grid, int i, int j, int xore) {
        int n = grid.size(), m = grid[0].size();

        if (i >= n || j >= m) return;

        xore ^= grid[i][j];

        if (i == n - 1 && j == m - 1) {
            ans = min(ans, xore);
            return;
        }

        if (dp[i][j][xore] != -1) return;
        dp[i][j][xore] = 1;

        rec(grid, i + 1, j, xore);
        rec(grid, i, j + 1, xore);
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        dp = vector<vector<vector<int>>>(n,
              vector<vector<int>>(m, vector<int>(1024, -1)));

        rec(grid, 0, 0, 0);
        return ans;
    }
};