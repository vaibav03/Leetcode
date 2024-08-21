class Solution {
public:
    int jump(vector<int>& nums) {
          int n = nums.size();
        vector<int> dp(n,0);

        dp[n-1]=0;

        for(int i=n-2;i>=0;i--){
            if(nums[i]==0) 
            dp[i]=1000000;

          int  ans=1000000;  
          for(int j=1;j<=nums[i];j++){
          if(i+j<nums.size())
          ans=min(dp[i+j]+1,ans);
          }
          dp[i]=ans;
        }
        return dp[0];

    }
};