class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int mini = -1,maxi = -1,ans{};
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(mini == -1 || nums[mini]>nums[i]) mini = i;
            if(maxi == -1 || nums[maxi]<nums[i]) maxi = i;

            if(abs(nums[maxi] - nums[mini]) > k ){ ans++;  mini = i; maxi = i; }
        }
        return ans+1;
    }
};