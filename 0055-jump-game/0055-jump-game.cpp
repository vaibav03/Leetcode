class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxiReach = 0, lim = 0;
        for(int i=0;i<nums.size();i++){
            if(maxiReach < i) return false;
            maxiReach = max(maxiReach, nums[i] + i);
        }
        return true;
    }
};