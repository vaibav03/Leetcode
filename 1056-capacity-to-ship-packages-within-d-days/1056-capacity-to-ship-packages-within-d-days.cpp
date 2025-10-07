class Solution {
public:
    int lb(vector<int> &nums,int cap){
        int sum{},part{};
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=cap) sum+=nums[i];
            else{
                if(nums[i]>cap) return INT_MAX;
                part++;
                sum = nums[i];
            }
        }
        return part+1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1,r = 1e9,ans{};

        while(l<=r){
            int mid = (l+r)/2;
            if(lb(weights,mid) <= days){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};