class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int maxi = INT_MIN,ans{};
       for(int i=0;i< nums.size();i++){
        if(maxi < nums[i] + k){
            maxi = max(nums[i] - k,maxi+1);
            ans++;
        }else {
            continue;
        }
       }
       return ans;
    }
};