class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        dp[1]=1;

        for(int i=1;i<=n;i++)
        {
         for(int j=1;j<=sqrt(n);j++)
         {
          if( (i)-(j)*(j) >=0 )  
          dp[i]=min(dp[i],dp[i-j*j]+1); 
          else
          break; 
         }   
        }

        return dp[n];
    }
};