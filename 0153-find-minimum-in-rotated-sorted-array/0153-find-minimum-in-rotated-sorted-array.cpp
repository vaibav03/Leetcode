class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0 , high = nums.size()-1,ans=INT_MAX;
        if(nums.size()==2) return min(nums[0],nums[1]);
        while(high>=low){
            int  mid = (high+low)/2;
            cout<<low<<" "<<high<<endl;
            if(nums[mid]>=nums[low] && nums[mid]>nums[high])
            {
                low = mid +1;
            } else{
                high = mid-1;
            }
            ans = min(ans,nums[mid]);
        }
        return ans;
    }
};