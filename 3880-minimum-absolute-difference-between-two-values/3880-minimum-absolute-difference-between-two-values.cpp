class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[i] == 1 && nums[j]==2){
                    ans = min(ans ,abs(j-i));
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
        
    }
};