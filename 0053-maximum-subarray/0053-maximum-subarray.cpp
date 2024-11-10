class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int present = -10000,ans = -100000;

        for(int i=0;i<nums.size();i++)
        {
          present = max(present+nums[i],nums[i]);

          ans = max(ans,present);  
        }
        return ans;

    }
};