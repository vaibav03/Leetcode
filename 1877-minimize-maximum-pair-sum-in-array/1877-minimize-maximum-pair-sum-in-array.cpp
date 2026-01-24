class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i{},j = nums.size() - 1,ans = -1;
        while(i<j){
            ans = max(ans, nums[i] + nums[j]);
            i++;
            j--;
        }
        return ans;
    }
};