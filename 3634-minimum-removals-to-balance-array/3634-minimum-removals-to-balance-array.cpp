class Solution {
public:
    int ub(vector<int> &nums, long long val){
        int l = 0, r= nums.size()-1,ans = nums.size();
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid] > val){ r = mid-1; ans = mid; }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums[0]*1ll*k >= nums[nums.size() - 1]) return 0;

        int ans = nums.size();
       
        for(int i=0;i<nums.size();i++){
            int u = ub(nums,nums[i]*1ll*k);
            int pres = i + nums.size() - u;
            ans = min(ans , pres);  
        }
        return ans;
    }
};