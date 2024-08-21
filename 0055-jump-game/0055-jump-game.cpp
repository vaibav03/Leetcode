class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[n-1]=true;
        for(int i=n-2;i>=0;i--){
            if(nums[i]==0) dp[i]=0;
          bool ans{};  
          for(int j=1;j<=nums[i];j++){
          if(i+j<nums.size())
          ans|=dp[i+j];
          else 
          {
           ans=true;
           break; 
          } 
          }
          dp[i]=ans;
        }
        return dp[0];

    }

    bool f(vector<int>nums,int i)
    {
      if(i>=nums.size()) return true;
      else if(nums[i]==0) {return false;}

      bool ans = false;
      for(int j=1;j<=nums[i];j++)
       ans|=f(nums,i+j);

     return ans;    
    }
};