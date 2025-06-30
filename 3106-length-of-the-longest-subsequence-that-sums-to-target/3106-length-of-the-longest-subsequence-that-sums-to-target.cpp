class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(target+1,-1));

        for(int i=0;i<nums.size();i++){
            dp[i][0] = 0;
        }

        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=target;j++){               
                dp[i][j] = dp[i-1][j];

            if (j >= nums[i - 1] && dp[i - 1][j - nums[i - 1]] != -1)
                dp[i][j] = max(1 + dp[i - 1][j - nums[i - 1]], dp[i][j]);  
            }
        }
        return dp[nums.size()][target];
    }
};