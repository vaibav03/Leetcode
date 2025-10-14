class Solution {
public:
    bool solve(vector<int> &nums,vector<int> &vis,int k,int target, int ind,int sum){
        if(k==0 ) return true;

        if(sum == target) return solve(nums,vis,k-1,target,0,0);

        if(ind == nums.size())  return false;

        bool ans = false;
        for(int i=ind;i<nums.size();i++){
            if(!vis[i] && sum+nums[i]<=target ){
                vis[i] = 1;
               ans|= solve(nums,vis,k,target,i+1,sum+nums[i]);
               vis[i] = 0;
            }
            }
        

       return ans;

    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(),nums.end(),0) ;

    if(sum%k !=0 ) return false;

    int target = accumulate(nums.begin(),nums.end(),0) /k;
      vector<int> vis(nums.size(),0);
        
      return solve(nums,vis,k,target,0,0);  
    }
};