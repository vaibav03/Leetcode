class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int pre = nums[0],suf = nums[n-1];
        for(int i=1;i<nums.size();i++){
            ans[i] += i*nums[i] - pre;
            pre+=nums[i];
        }


        for(int i=n-2;i>=0;i--){
            ans[i] += (suf - (n-i-1)*nums[i]);
            suf+=nums[i];
        }
        return ans;
    }
};