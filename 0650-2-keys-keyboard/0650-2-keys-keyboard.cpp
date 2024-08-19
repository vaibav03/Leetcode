class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n,INT_MAX);
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
         for(int j=0;j<i;j++)
         {
          if( (i+1)%(j+1)==0 && dp[j]!=INT_MAX )
          {
            dp[i] = min(dp[j]+(i+1)/(j+1),dp[i]);
          }  
         }
        }
        return dp[n-1]-1;
        }
};