class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        for(int i=k-1;i<nums.size();i++){
            //cout<<i<<" "<<i-k+1<<endl;
            ans = min(nums[i] - nums[i-k+1],ans);
        }
        return ans;
    }
};