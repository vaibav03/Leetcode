class Solution {
public:
    unordered_map<double, unordered_map<int,int>> dp;

    int rec(vector<int>& nums, double val, long long k ,int ind){
        if(ind == nums.size())
            return (fabs(val - k) < 1e-9);

        if(dp.count(val) && dp[val].count(ind))
            return dp[val][ind];

        int count = 0;

        count += rec(nums, val * nums[ind], k, ind+1);
        count += rec(nums, val / nums[ind], k, ind+1);
        count += rec(nums, val, k, ind+1);

        return dp[val][ind] = count;
    }

    int countSequences(vector<int>& nums, long long k) {
        return rec(nums, 1, k, 0);
    }
};