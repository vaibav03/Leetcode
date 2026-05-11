class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),INT_MIN);
        dp[0] = 0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(abs(nums[i] - nums[j]) <= target){
                dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
    return (dp.back() <= 0 ) ? -1 : dp.back();
    }
};