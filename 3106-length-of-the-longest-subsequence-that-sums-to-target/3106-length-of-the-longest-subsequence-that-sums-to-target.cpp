class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1e9));
        if(nums[0] <= target)
        dp[0][nums[0]] = 1;

        for(int i=0;i<n;i++) dp[i][0] = 0;

        for(int i=1;i<nums.size();i++){
            for(int j=0;j<=target;j++){
                int take = -1e9;
                if(j >= nums[i] && dp[i-1][j-nums[i]]!=-1e9)
                 take = dp[i-1][j-nums[i]] + 1;
                int nottake = dp[i-1][j];

                dp[i][j] = max(take,nottake);

            }

        }
        return (dp[n-1][target] <= 0 ) ?  -1 : dp[n-1][target];

    }
};