class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        unordered_map<int,long long> cnt,sum;
        long long ans{};
        int mod = 1e9 +7;
        for(auto num : nums){
            sum[num] = (sum[num] + sum[num-1] + sum[num+1] + (cnt[num+1]+cnt[num-1]+1)*num)%mod;
            cnt[num] = ( cnt[num] + cnt[num-1] + cnt[num+1] +1)%mod;
        }

        for(auto it : sum){
            // cout<<it.second
            ans = (ans + it.second)%mod;
        }
        return ans;
    }
};