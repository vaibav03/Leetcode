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
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(target,n,k,dp);
    }
};