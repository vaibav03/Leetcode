class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<vector<vector<int>>> dp;

    int solve(int m, int n, int moves, int r, int c) {
        if (r < 0 || c < 0 || r >= m || c >= n)
            return 1;  
        if (moves == 0)
            return 0; 

        if (dp[r][c][moves] != -1)
            return dp[r][c][moves];

        long long ans = 0;
        for (auto &d : directions) {
            ans += solve(m, n, moves - 1, r + d[0], c + d[1]);
            ans %= mod;
        }
        return dp[r][c][moves] = ans;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.assign(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return solve(m, n, maxMove, startRow, startColumn);
    }
};
