class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long  count{},ans{},minDiff=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<(nums[i]^k)){
                count++;
                ans+=(nums[i]^k);
            }else{
                ans+=nums[i];
            }
            minDiff = min( minDiff , 1ll*abs(nums[i] - (nums[i]^k)) );
        }
        if(count&1) ans-=minDiff;

        return ans;
    }
};