class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int diff{};
        for(int i=0;i<nums.size();i++){
            if(i==0) diff = max(diff,abs(nums[nums.size()-1]-nums[0]));

            else diff = max(diff,abs(nums[i] - nums[i-1]));
        }
        return diff;
    }
};