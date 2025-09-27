class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans{},n = nums.size();

        for(int k=n-1;k>=2;k--){
            int j = k-1,i{};
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                     ans+=(j-i);
                     j--;
                     }
                else {
                    i++;
                }
            }
        }
        return ans;
    }
};