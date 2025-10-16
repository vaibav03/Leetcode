class Solution {
public:
    bool isPossible(vector<int>& nums,int window){
        vector<int> dp(nums.size(),1);
        int ans{};
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1])
             dp[i] = 1 + dp[i-1];

             if(dp[i] >= window && i-window>=0 && dp[i-window] >= window ) return true;
        }

        return false;

    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int l = 1, h = nums.size(),ans=1;

        while(l<=h){
            int mid = (l+h)/2;
            if(isPossible(nums,mid)) {
                l = mid +1;
                ans = mid;
            }else{ h = mid - 1;}
        }
        return ans;
    }
};