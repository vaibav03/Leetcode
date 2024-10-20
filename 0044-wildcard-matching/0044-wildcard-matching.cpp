class Solution {
public:

    bool isMatch(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));

        dp[0][0] = 1;
        for(int i=0;i<s2.size();i++){
          if(s2[i]=='*')
          dp[0][i+1]=true;
          else
          break;
        } 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
             if(s1[i-1]==s2[j-1] || s1[i-1]=='?' || s2[j-1]=='?')
                dp[i][j]=dp[i-1][j-1];

              else if(s1[i-1]=='*' || s2[j-1]=='*')
              {
               dp[i][j] = dp[i-1][j]|dp[i][j-1];
               }
        }
       
    } 
    return dp[n][m];
    }
};