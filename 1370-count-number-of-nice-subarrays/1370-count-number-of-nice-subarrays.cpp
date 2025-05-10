class Solution {
public:
int f(vector<int> nums, int goal){
    if(goal<0) return 0;
        int l{},r{},oddNum{},ans{};
        if(nums[0]%2) oddNum++;

        while(l<=r && r<nums.size()){
            if(oddNum<=goal){
                ans+=(r-l+1);
                r++;
                if(r<nums.size() && nums[r]%2) oddNum++;
            } else{
                while(l<nums.size() && nums[l]%2==0) l++;
                l++;
                oddNum--;
                if(l>r){
                    r=l;
                    if(r<nums.size() && nums[r]%2) oddNum++;
                }
            }
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
       return f(nums,k) - f(nums,k-1);
    }
};