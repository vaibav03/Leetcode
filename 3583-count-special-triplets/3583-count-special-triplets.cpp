class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        map<int,int> pre,suf;
        for(auto x : nums){
            suf[x]++;
        }

        long long ans{},mod = 1e9 +7 ;
        for(int i=0;i<nums.size();i++){
            suf[nums[i]]--;
            ans = ( ans + suf[2*nums[i]] *1ll * pre[2*nums[i]] )%mod;
            pre[nums[i]]++;
        }
        return ans;
    }
};