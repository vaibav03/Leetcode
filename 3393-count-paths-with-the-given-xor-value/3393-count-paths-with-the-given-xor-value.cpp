class Solution {
public:
     int MOD = 1e9 + 7;
    int n, m;
    int rec(vector<vector<int>>& grid, int k, int i, int j, int xore,vector<vector<vector<int>>> &dp) {
        if (i >= n || j >= m) return 0;

        xore ^= grid[i][j];

        if (i == n - 1 && j == m - 1)
            return xore == k;

        int &ans = dp[i][j][xore];
        if (ans != -1) return ans;

        ans = 0;
        ans = (ans + rec(grid, k, i + 1, j, xore,dp)) % MOD;
        ans = (ans + rec(grid, k, i, j + 1, xore,dp)) % MOD;

        return ans;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(20, -1)));

        return rec(grid, k, 0, 0, 0,dp);
    }
};
