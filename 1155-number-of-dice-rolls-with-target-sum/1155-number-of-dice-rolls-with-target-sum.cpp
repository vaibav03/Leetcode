class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int target,int n,int k, vector<vector<int>> &dp){
        if(target == 0 && n == 0) return 1;
        else if(n == 0 || target <= 0) return 0;

        if(dp[n][target] != -1) return dp[n][target];
        int ans{};
        for(int i=1;i<=k;i++){
             ans = (ans + solve(target - i , n-1,k,dp))%mod;
        }
        return dp[n][target] = ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j = 0;j<=target;j++){
                for(int val=1;val<=k;val++){
                    if(j>=val)
                    dp[i][j] = (dp[i][j] + dp[i-1][j - val])%mod;
                }
           }
        }
        return dp[n][target];
    }
};