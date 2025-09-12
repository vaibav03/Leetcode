class Solution {
public:
    int solve(int ind, int prevIndex, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == nums.size()) return 0;
        
        if (dp[ind][prevIndex+1] != -1) return dp[ind][prevIndex+1];
        
        int notTake = solve(ind+1, prevIndex, nums, dp);
        
        int take = 0;
        if (prevIndex == -1 || nums[ind] > nums[prevIndex]) {
            take = 1 + solve(ind+1, ind, nums, dp);
        }
        
        return dp[ind][prevIndex+1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, -1, nums, dp);
    }
};
