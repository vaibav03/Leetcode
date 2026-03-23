class Solution {
public:
    int rec(vector<int> & nums, int ind, int target,int curr, unordered_map<int, unordered_map<int,int>>  &dp){
        if(ind == nums.size() && curr == target) return 0;
        else if(ind == nums.size() ) return 1e7;

        if(dp.find(ind)!=dp.end() && dp[ind].find(curr)!=dp[ind].end()) return dp[ind][curr];
        
        int take = rec(nums,ind+1,target, curr^nums[ind],dp);
        int nottake = 1 + rec(nums,ind+1,target, curr,dp);

        return dp[ind][curr] = min(take,nottake);
    }
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, unordered_map<int,int>>  dp;
        int ans  = rec(nums,0,target,0,dp);

        return (ans >= 1e7) ? -1 : ans;
    }
};