class Solution {
public:
    int minOperations(vector<int>& nums) {
        int  op{};
        int i;
        for(i=2;i<nums.size();i++){
            if(nums[i - 2] == 0){
                op++;
                nums[i-2] = 1;
                nums[i-1] = !nums[i-1];
                nums[i] = !nums[i];
            }
        }
        if(nums[i-1]==0 || nums[i-2]==0 ) return - 1;
        else return op;
    }
};