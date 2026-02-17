class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int sum;
        while(l<r){
            sum = nums[l] + nums[r];
            if(sum == target) return {l+1,r+1};

            if(sum < target){
                l++;
            }else r--;

        }
        return {-1,-1};
    }
};