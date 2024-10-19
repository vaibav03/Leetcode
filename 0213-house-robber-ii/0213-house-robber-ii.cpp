class Solution {
public:
  int rob1(vector<int>& nums) {
 if(nums.size() == 0) return 0; 
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return max(nums[0], nums[1]);

    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[nums.size() - 1];
   }
    
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;

        for(int i=0;i<nums.size();i++){
            if(i==0)
            temp2.push_back(nums[i]);

            else if(i==nums.size()-1)
            temp1.push_back(nums[i]);

            else{
                temp1.push_back(nums[i]);
                temp2.push_back(nums[i]);
            }
        }

        return max(rob1(temp1),rob1(temp2));
    }
};