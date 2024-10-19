class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),1e8));

       for(int i=0;i<matrix.size();i++){
        dp[0][i] = matrix[0][i];
       }

       for(int i =1;i<matrix.size();i++)
       {
        for(int j=0;j<matrix.size();j++){
           int up_left=INT_MAX,up_right=INT_MAX;
           for(int k=1;k<matrix.size();k++){
            if( (j+k)<matrix.size())
            up_left = dp[i-1][j+k];

            if(j-k>=0)
            up_right = dp[i-1][j-k];

            dp[i][j] = min(dp[i][j],min(up_left,up_right)+matrix[i][j]);
           }
        }
        }
          
        int ans = INT_MAX;
        for(int i=0;i<matrix.size();i++){
            ans = min(ans,dp[matrix.size()-1][i]);
        }
        return ans;
    }
};