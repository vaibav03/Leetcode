class Solution {
public:
    int ans{};
    int  subseq(string &s,string &t,int i,int j,vector<vector<int>> &dp){
        if(j == -1) {
            ans++;
            return 1;
        }else if(i == -1) {
            return 0 ;
        }

        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        if(s[i] == t[j]) {
            return dp[i][j] = subseq(s,t,i-1,j-1,dp) + subseq(s,t,i-1,j,dp);;
        } else{ 
             return dp[i][j] = subseq(s,t,i-1,j,dp);
         }
    }
    int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])% 1000000007;
            } else {
                dp[i][j] = dp[i-1][j]% 1000000007;
            }
        }
    }

    return dp[n][m];
}

};