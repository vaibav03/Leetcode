class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const int MOD = 1e9+7;

        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(k, 0)));

        dp[1][1][grid[0][0] % k] = 1;

        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (i==1 && j==1) continue; 

                int val = grid[i-1][j-1];
                for (int x=0; x<k; x++) {
                    int mod = (x - val) % k;
                    if (mod < 0) mod += k;

                    int top = dp[i-1][j][mod];
                    int left = dp[i][j-1][mod];

                    dp[i][j][x] = ( (long long)top + left ) % MOD;
                }
            }
        }

        return dp[m][n][0];  
    }
};
