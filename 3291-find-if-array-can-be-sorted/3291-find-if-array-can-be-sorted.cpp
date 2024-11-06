class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int curr_max{},curr_min{},prev_max{},prevbit=-1;
        for(int i=0;i<nums.size();i++){
          int bit = __builtin_popcount(nums[i]);
          if(prevbit==bit){
            curr_max = max(nums[i],curr_max);
            curr_min = min(nums[i],curr_min);
          }
          else if(curr_min < prev_max){
            return false;
          }
          else {
            prev_max = curr_max;
            curr_min = curr_max = nums[i];
            prevbit = bit;
          }

        }
        return (curr_min>=prev_max);
    }
};