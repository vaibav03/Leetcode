class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e6,curr = -1e6;
        for(int i=0;i<nums.size();i++){
         curr = max(nums[i],curr+nums[i]);
         ans=max(ans,curr);    
        }
        return ans;
    }
};