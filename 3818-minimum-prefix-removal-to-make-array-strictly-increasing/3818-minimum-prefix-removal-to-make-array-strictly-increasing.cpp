class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int i = nums.size()-1;
        while(i>0 && nums[i]>nums[i-1]){
            i--;
        }
        return i;
    }
};