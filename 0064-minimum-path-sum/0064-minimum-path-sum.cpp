class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
     vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),1e8));
     dp[0][0] = grid[0][0];
     
     for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            int up= 1e8,left = 1e8;
             if(!i && !j)
             continue;
             
             if(i!=0)
             up = dp[i-1][j];

             if(j!=0)
             left = dp[i][j-1];

            dp[i][j] = min(up,left) + grid[i][j]; 
        }
     }
     return dp[grid.size()-1][grid[0].size()-1];   
    }
};