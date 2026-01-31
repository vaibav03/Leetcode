class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> maxi(n+1,vector<int>(m+1, INT_MIN));
        maxi[n-1][m-1] =  grid[n-1][m-1];
        long long ans = INT_MIN;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int best  = max(maxi[i+1][j], maxi[i][j+1]);
                if(best != INT_MIN )
                ans = max(ans ,1ll*( best - grid[i][j]));       
                maxi[i][j] = max(grid[i][j] ,best ); 
            }
        }
        return ans;
    }
};