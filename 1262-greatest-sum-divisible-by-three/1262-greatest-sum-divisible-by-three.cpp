class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(3,INT_MIN));
        dp[0][0] = 0;
        int ans = 0;
        for(int i=1;i<=nums.size();i++){
            for (int r = 0; r < 3; r++) {
                dp[i][r] = dp[i-1][r];
            }

            for(int j=0;j<3;j++){
            int val = (nums[i-1]+j) % 3;
            dp[i][val] = max(dp[i-1][j] + nums[i-1],dp[i][val]);
            }
            ans = max(dp[i][0],ans);
        }


        return ans;
    }
};