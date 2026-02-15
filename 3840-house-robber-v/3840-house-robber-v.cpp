class Solution {
public:
    long long rec(vector<int>& nums, vector<int>& colors, int ind, bool taken,vector<vector<long long>> &dp){
        if(ind == nums.size()) return 0;

        if(dp[ind][taken] != -1) return dp[ind][taken];

         long long take = 0, nottake = 0;
        if(!taken || (ind>0 && colors[ind]!=colors[ind-1])) take = nums[ind]*1ll +  rec(nums, colors,ind+1,true,dp);

        nottake = rec(nums,colors,ind+1,false,dp);  
        return dp[ind][taken] = max(take,nottake);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return rec(nums,colors,0,false,dp);
    }
};