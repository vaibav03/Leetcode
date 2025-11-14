class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,1e9));

        for(int j = 0; j <= amount; j++){
            if(j % coins[0] == 0){
                dp[0][j] = j / coins[0];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int take = 1e9;
                if(j>=coins[i])
                 take = dp[i][j-coins[i]] + 1;
            
                int nottake = dp[i-1][j];
                
                dp[i][j] = min(take,nottake);
            }
        }
        return (dp[n-1][amount] == 1e9) ? -1 : dp[n-1][amount];
    }
};