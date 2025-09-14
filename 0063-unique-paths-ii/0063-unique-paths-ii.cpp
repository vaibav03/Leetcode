class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        if(grid[0][0]==1) return 0;
        
        dp[0][0] = 1;
        for(int i=1;i<n;i++) {
            if(grid[i][0]!=1) dp[i][0] = dp[i-1][0]; 
        }
        for(int j=1;j<m;j++){
        if(grid[0][j]!=1) dp[0][j] = dp[0][j-1]; 
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j] == 1) continue; 
                int top{},left{};
                if(i!=0)
                 top = dp[i-1][j];
                if(j!=0)
                left = dp[i][j-1];  

                dp[i][j] = top + left;
            }
        }
        return dp[n-1][m-1];
    }
};