class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
       vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(m,vector<long long>(k+1,INT_MIN)));
       for(int i=0;i<=k;i++) dp[0][0][i] = 0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int x = 0;x<=k;x++){
                long long curr=INT_MIN,cost = (grid[i][j] == 0) ? 0 : 1;
                if(i == 0 && j ==0) continue;
                if(i>0 && x-cost>=0) curr = max(curr, dp[i-1][j][x-cost]+grid[i][j]);

                if(j>0 && x-cost>=0) curr = max(curr, dp[i][j-1][x-cost]+grid[i][j]);

                dp[i][j][x] = max(curr,dp[i][j][x]);
            }
        }
       }
    long long ans = INT_MIN;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[n - 1][m - 1][c]);
        }
        return ans < 0 ? -1 : ans;
    }
};