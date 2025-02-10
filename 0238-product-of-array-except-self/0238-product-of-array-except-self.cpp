class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size());
        pre[0] = 1;
        for(int i=1;i<nums.size();i++){
            pre[i] = pre[i-1]*nums[i-1];
        }
        int suf=1;
        for(int i=nums.size()-1;i>=0;i--){
            pre[i]*=suf;
            suf*=nums[i];
        }
        return pre;
    }
};