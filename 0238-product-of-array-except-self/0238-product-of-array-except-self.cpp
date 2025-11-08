class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(),post = 1;
        vector<int> ans(n,1);
        for(int i=1;i<nums.size();i++){
            ans[i]*=nums[i-1];
            ans[i]*=ans[i-1];
        }

        for(int i = n-1;i>=0;i--){
            ans[i]*=post;
            post*=nums[i];
        }
        return ans;
    }
};