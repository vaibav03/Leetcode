class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(),INT_MAX);
        dp[0] = min(costs[0],min(costs[1],costs[2]));
        for(int i=1;i<days.size();i++){
            int last7=i,last30=i;
            while(last7>-1 && days[last7]>days[i]-7 ){
                last7--;
            }
            while(last30>-1 && days[last30]>days[i]-30){
                last30--;
            }

            dp[i] = min(dp[i],dp[i-1]+costs[0]);
            if(last7==-1)
            dp[i] = min(dp[i],costs[1]);
            else
            dp[i] = min(dp[i],dp[last7]+costs[1]);
            if(last30==-1)
            dp[i] = min(dp[i],costs[2]);
            else
            dp[i] = min(dp[i],dp[last30]+costs[2]);
        }
        return dp[days.size()-1];
    }
};