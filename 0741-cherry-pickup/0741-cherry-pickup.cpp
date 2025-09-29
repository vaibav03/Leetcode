
class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& grid, int r1, int c1, int c2) {
        int r2 = r1 + c1 - c2;  // because steps are equal
        if (r1 >= n || c1 >= m || r2 >= n || c2 >= m) return -1e8;
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1) return -1e8;

        // reached destination
        if (r1 == n-1 && c1 == m-1 && r2==n-1) return grid[r1][c1];

        if (dp[r1][c1][c2] != INT_MIN) return dp[r1][c1][c2];

        int cherries = grid[r1][c1];
        if (c1 != c2 || r1 != r2) cherries += grid[r2][c2]; // avoid double count

        int best = max({
            solve(grid, r1+1, c1, c2),     // r1 down, r2 down
            solve(grid, r1, c1+1, c2+1),   // r1 right, r2 right
            solve(grid, r1+1, c1, c2+1),   // r1 down, r2 right
            solve(grid, r1, c1+1, c2)      // r1 right, r2 down
        });

        return dp[r1][c1][c2] = cherries + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n, vector<vector<int>>(m, vector<int>(m, INT_MIN)));
        return max(0, solve(grid, 0, 0, 0));
    }
};
