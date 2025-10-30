class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int left = 0,right=total, ans = 0;

        for (int i = 0; i < nums.size(); ++i) {
            left+=nums[i];
            right-=nums[i];
            if(nums[i] ==0){
            if(left == right) ans+=2;
            else if(abs(left-right) == 1) ans+=1;
            }
        }

        return ans;
    }
};
