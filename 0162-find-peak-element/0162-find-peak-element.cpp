class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 1 , r = nums.size() - 2,ans = -1;
        if(nums.size() == 1 || nums[0] > nums[1]) return 0;
        else if(nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;

        while(l<=r){
            int mid = (l+r) / 2;
            if(nums[mid] >= nums[mid - 1] && nums[mid] > nums[mid+1]) return mid;

            if(nums[mid] > nums[mid - 1] && nums[mid] < nums[mid+1]){
                l = mid+1;
            }else if(nums[mid] < nums[mid - 1] && nums[mid] > nums[mid+1]){
                r = mid - 1;
            }else{
                r = mid-1;
            }
            cout<<mid<<" ";
        }
        return ans;
    }
};