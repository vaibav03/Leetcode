class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mini=INT_MAX,maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            mini = min(mini,1ll*nums[i]);
            maxi = max(maxi,1ll*nums[i]);
        }
        return 1ll*k*(maxi-mini);
    }
};