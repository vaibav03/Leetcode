class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,1e9));

        for(int i=0;i<n;i++) dp[i][0] = 0;
        for(int i=1;i*coins[0]<=amount;i++) dp[0][coins[0]*i] = i;

        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int take = INT_MAX,nottake = dp[i-1][j];
                if(coins[i]<=j){take = 1 + dp[i][j-coins[i]];}

                dp[i][j] =  min(take,nottake);
            }
        }
        return (dp[n-1][amount] == 1e9) ? -1 : dp[n-1][amount] ;
    }
};