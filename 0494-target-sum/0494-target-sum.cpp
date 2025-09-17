class Solution {
public:
    int solve(vector<int>& nums, int target,int ind,vector<int> &dp){
        if(target==0 && ind<0) return 1;
        if(ind<0) return 0;

        return dp[ind] = solve(nums,target-nums[ind],ind-1,dp) + solve(nums,target+nums[ind],ind-1,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n);
        return solve(nums,target,n-1,dp);
    }
};