class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string srev = s;
        int n = s.size();
        reverse(srev.begin(),srev.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int take{},nottake{};
                if(s[i-1] == srev[j-1]) take = 1 + dp[i-1][j-1];
                nottake = max(dp[i-1][j],dp[i][j-1]);

                dp[i][j] = max(take,nottake); 
            }
        }
        return dp[n][n];
    }
};