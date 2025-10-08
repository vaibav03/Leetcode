class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> hash(1e4+1,0),dp(1e4+1,0);
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(int i=1;i<dp.size();i++){
            cout<<i<<endl;
            if(i==1)
            dp[i] = hash[i]*i;
            else
            dp[i] = max(dp[i-1],dp[i-2]+hash[i]*i);
        }
        return dp[1e4];
    }
};