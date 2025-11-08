class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(auto x : nums)cout<<x<<" ";
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            int j = i+1, k = nums.size()-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<nums.size()-1 && nums[j]==nums[j+1]) j++;
                    
                    j++;
                    while(k>0 && nums[k] == nums[k-1] ) k--;

                    k--;
                }else if(sum>0){
                    
                    k--;
                }else{
                    j++;
                }   
            }
            while(i<nums.size()-1  && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};