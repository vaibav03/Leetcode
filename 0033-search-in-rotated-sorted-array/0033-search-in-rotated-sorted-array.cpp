class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0 , high = nums.size()-1,ans=INT_MAX;
        while(high>=low){
            int  mid = (high+low)/2;
            cout<<low<<" "<<high<<endl;
            if(nums[mid] == target) return mid;

            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && nums[mid]>=target)
                high = mid - 1;
                else
                low = mid+1;
            }
            else if(nums[high]>=nums[mid]){
                if(nums[high]>=target && nums[mid]<=target)
                low = mid + 1;
                else 
                high = mid-1;
            }
        }
        return -1;
    }
};