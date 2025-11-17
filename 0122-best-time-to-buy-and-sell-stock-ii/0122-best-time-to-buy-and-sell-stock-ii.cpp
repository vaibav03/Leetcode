class Solution {
public:
    int solve(vector<int>& prices,int ind, int buy){
        if(ind >= prices.size()) return 0;

        if(buy == 1){
            return max(prices[ind]  + solve(prices,ind+1,!buy), solve(prices,ind+1,buy));
        }else{
            return max(-prices[ind]  + solve(prices,ind+1,!buy), solve(prices,ind+1,buy));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int i = n-1;i>=0;i--){
            dp[i][0] = max(-prices[i] + dp[i+1][1], dp[i+1][0]);
            dp[i][1] = max(+prices[i] + dp[i+1][0], dp[i+1][1]);
        }
        return dp[0][0];
    }
};