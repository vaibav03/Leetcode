class Solution {
public:
    
    int solve(vector<vector<int>> &grid, int i1,int j1,int j2,vector<vector<vector<int>>> &dp){
        if( j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size()) return -1e8;

        if(dp[i1][j1][j2]!=-1) return dp[i1][j1][j2];

        if(i1 == grid.size()-1) {
            if(j1==j2) return grid[i1][j1];
            else return grid[i1][j1] + grid[i1][j2];
        }
        int maxi{};

        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                maxi = max(maxi,solve(grid,i1+1,j1+dj1,j2+dj2,dp));
            }
        }
        if(j1==j2)
        return dp[i1][j1][j2] = maxi + grid[i1][j1];
        else return dp[i1][j1][j2]  = maxi + grid[i1][j1] + grid[i1][j2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return solve(grid,0,0,m-1,dp);
    }
};