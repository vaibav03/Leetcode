class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mine=nums[0],ans=INT_MIN;
        for(int i=1;i<nums.size();i++){
          ans = max(ans, nums[i] - mine);
            mine = min(mine,nums[i]);
        }
        return (ans>0) ? ans : -1;
    }
};