class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums,vector<int> &vis,vector<int>&curr){
        if(curr.size() == nums.size()) {ans.push_back(curr);  return;}
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                curr.push_back(nums[i]);
                vis[i] = 1;
                solve(nums,vis,curr);
                vis[i] = 0;
                curr.pop_back();
                while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> vis(nums.size()),curr;
        sort(nums.begin(),nums.end());
        solve(nums,vis,curr);
        return ans;
    }
};