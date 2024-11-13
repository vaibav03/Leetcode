class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) 
        return {-1,-1};
        int l{}, r = nums.size(),ansr=-1,ansl=-1;
        while(l<=r && l<nums.size() && r>=0){
            int mid = (l+r)/2;
            if(nums[mid]<target)
            l = mid+1;
            else if(nums[mid]>target)
            r = mid-1;
            else{
                ansl=mid;
                r=mid-1;
            }
        }

        r=nums.size()-1;
        while(l<=r && l<nums.size() && r>=0){
            int mid = (l+r)/2;
            if(nums[mid]<target)
            l = mid+1;
            else if(nums[mid]>target)
            r = mid-1;
            else{
                ansr=mid;
                l=mid+1;
            }
        }
        return {ansl,ansr};
    }
};