class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int mini = -1,maxi = -1,badi = -1;
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            mini = (nums[i] == minK) ? i : mini;
            maxi = (nums[i] == maxK) ? i : maxi;
            if(nums[i] >= minK && nums[i]<=maxK ){
              ans+= 1ll*max(0,min(mini,maxi) - badi);
             }
            else badi = i;

        }
        return ans;
    }
};