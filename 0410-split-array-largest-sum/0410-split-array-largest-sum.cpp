class Solution {
public:
    bool isPossible(vector<int>& nums, int maxSum, int k){
        int sum{};
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i] <= maxSum){ sum+=nums[i];}
            else{
                sum = nums[i];
                k--;
            }
        }
        return (k>0);
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(),nums.end()) , r = accumulate(nums.begin(),nums.end(),0),ans = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(isPossible(nums,mid,k)){ ans = mid; r = mid - 1;}
            else l = mid + 1;
        }
        return ans;
    }
};