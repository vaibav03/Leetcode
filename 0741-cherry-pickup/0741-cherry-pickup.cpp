class Solution {
public:

int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(m+1, INT_MIN)));
    dp[1][1][1] = grid[0][0];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++){
                if(i==1 && j==1 && k==1) continue;
                if(i+j-k<1 || i+j-k>n)  continue;
                if(grid[i-1][j-1] == -1 || grid[i+j-k-1][k-1]==-1) continue;
                dp[i][j][k] = max({dp[i-1][j][k],dp[i][j-1][k],dp[i-1][j][k-1],dp[i][j-1][k-1]});
                if(j==k) dp[i][j][k]+=grid[i-1][j-1];
                else dp[i][j][k]+=(grid[i-1][j-1]+grid[i+j-k-1][k-1]);
            }
        }
    }
    return max(0,dp[n][m][m]);
} };