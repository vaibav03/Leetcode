class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){ dp[i][j] = grid[i][j]; continue;}
                
                
                int top =  (i==0) ? 1e9 : dp[i-1][j];
                int left = (j==0) ?  1e9 : dp[i][j-1];
                cout<<i<<" "<<j<<" "<<top<<" "<<left<<endl;

                dp[i][j] = grid[i][j] + min(top,left);
            }
        }
        return dp[n-1][m-1];
    }
};