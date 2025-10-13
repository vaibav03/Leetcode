class Solution {
public:
    int solve(string word1,string word2, int i , int j,vector<vector<int>> &dp){
        if(j == word2.size()){
            return word1.size() - i ;
        }else if(i == word1.size()){
            return word2.size() - j ;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 1e8;
        if(word1[i] == word2[j]) {
            ans = min(ans ,solve(word1,word2,i+1,j+1,dp));
        }else {
            ans  = min (ans,1 + solve(word1,word2,i+1,j,dp));
            ans = min(ans,1 + solve(word1,word2,i,j+1,dp));
            ans = min(ans, 1 + solve(word1,word2,i+1,j+1,dp));
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(),m =word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,1e8));

        for(int i=0;i<=n;i++) dp[i][0] = i;

        for(int j=0;j<=m;j++) dp[0][j] = j;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int ans = 1e8;
                if(word1[i-1] == word2[j-1]){
                    ans = min(ans,dp[i-1][j-1]);
                }else{
                    ans = min({
                    ans,
                    dp[i-1][j-1] + 1,
                    dp[i][j-1] + 1,
                    dp[i-1][j] + 1,
                });
                }
                dp[i][j] = ans;
            }
        }
        return dp[n][m];
    }
};